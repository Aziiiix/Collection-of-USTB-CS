import os
import mindspore as ms
import mindspore.context as context
#transforms.c_transforms用于通用型数据增强，vision.c_transforms用于图像类数据增强
import mindspore.dataset.transforms.c_transforms as C
import mindspore.dataset.vision.c_transforms as CV
#nn模块用于定义网络，model模块用于编译模型，callback模块用于设定监督指标
from mindspore import nn
from mindspore.train import Model
from mindspore.train.callback import LossMonitor
#设定运行模式为图模式，运行硬件为昇腾芯片
context.set_context(mode=context.GRAPH_MODE, device_target='Ascend') # Ascend, CPU, GPU

#根据数据集存储地址，生成数据集
def create_dataset(data_dir, training=True, batch_size=32, resize=(32, 32),
                   rescale=1/(255*0.3081), shift=-0.1307/0.3081, buffer_size=64):
    #生成训练集和测试集的路径
    data_train = os.path.join(data_dir, 'train') # train set
    data_test = os.path.join(data_dir, 'test') # test set
    #利用MnistDataset方法读取mnist数据集，如果training是True则读取训练集
    ds = ms.dataset.MnistDataset(data_train if training else data_test)
    #map方法是非常有效的方法，可以整体对数据集进行处理，resize改变数据形状，rescale进行归一化，HWC2CHW改变图像通道
    ds = ds.map(input_columns=["image"], operations=[CV.Resize(resize), CV.Rescale(rescale, shift), CV.HWC2CHW()])
    #利用map方法改变数据集标签的数据类型
    ds = ds.map(input_columns=["label"], operations=C.TypeCast(ms.int32))
    # shuffle是打乱操作，同时设定了batchsize的大小，并将最后不足一个batch的数据抛弃
    ds = ds.shuffle(buffer_size=buffer_size).batch(batch_size, drop_remainder=True)

    return ds

#定义模型结构，MindSpore中的模型时通过construct定义模型结构，在__init__中初始化各层的对象
class LeNet5(nn.Cell):
    def __init__(self):
        super(LeNet5, self).__init__()
        #定义卷积层，ReLU激活函数，平坦层和全连接层
        #conv2d的输入通道为1维，输出为6维，卷积核尺寸为5*5，步长为1，不适用padding
        self.conv1 = nn.Conv2d(1, 6, 5, stride=1, pad_mode='valid')
        self.conv2 = nn.Conv2d(6, 16, 5, stride=1, pad_mode='valid')
        self.relu = nn.ReLU()
        self.pool = nn.MaxPool2d(kernel_size=2, stride=2)
        self.flatten = nn.Flatten()
        self.fc1 = nn.Dense(400, 120)
        self.fc2 = nn.Dense(120, 84)
        self.fc3 = nn.Dense(84, 10)
    #构建Lenet5架构，x代表网络的输入
    def construct(self, x):
        x = self.relu(self.conv1(x))
        x = self.pool(x)
        x = self.relu(self.conv2(x))
        x = self.pool(x)
        x = self.flatten(x)
        x = self.fc1(x)
        x = self.fc2(x)
        x = self.fc3(x)

        return x

# 构建训练、验证函数进行模型训练和验证，提供数据路径，设定学习率，epoch数量
def train(data_dir, lr=0.01, momentum=0.9, num_epochs=3):
    #调用函数，读取训练集
    ds_train = create_dataset(data_dir)
    #调用函数，读取验证集
    ds_eval = create_dataset(data_dir, training=False)
    #构建网络
    net = LeNet5()
    #设定loss函数
    loss = nn.loss.SoftmaxCrossEntropyWithLogits(sparse=True, reduction='mean')
    #设定优化器
    opt = nn.Momentum(net.trainable_params(), lr, momentum)
    #设定损失监控
    loss_cb = LossMonitor(per_print_times=ds_train.get_dataset_size())
    #编译形成模型
    model = Model(net, loss, opt, metrics={'acc', 'loss'})
    # 训练网络，dataset_sink_mode为on_device模式
    model.train(num_epochs, ds_train, callbacks=[loss_cb], dataset_sink_mode=False)
    #用验证机评估网络表现
    metrics = model.eval(ds_eval, dataset_sink_mode=False)
    #输出相关指标
    print('Metrics:', metrics)

#main函数负责调用之前定义的函数，完成整个训练验证过程
if __name__ == "__main__":
    #argsparse是python的命令行解析的标准模块，可以通过命令行传入参数
    import argparse
    parser = argparse.ArgumentParser()
    #设定训练数据路径
    parser.add_argument('--data_url', required=False, default='./MNIST_Data/', help='Location of data.')
    parser.add_argument('--train_url', required=False, default=None, help='Location of training outputs.')
    args, unknown = parser.parse_known_args()
    #判断路径是否为obs路径，如果是，从obs路径下载数据
    if args.data_url.startswith('s3'):
        import moxing

        # WAY1: copy dataset from your own OBS bucket to container/cache.
        # moxing.file.copy_parallel(src_url=args.data_url, dst_url='MNIST/')

        # WAY2: copy dataset from other's OBS bucket, which has been set public read or public read&write.
        moxing.file.copy_parallel(src_url="s3://share-course/dataset/MNIST/", dst_url='MNIST/')

        data_path = 'MNIST/'
    else:
        data_path = os.path.abspath(args.data_url)
    #调用train函数，训练并验证模型
    train(data_path)

