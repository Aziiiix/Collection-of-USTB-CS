from PIL import Image
import qrcode
import cv2

def creatQR():
    # QRCode（）这里我们创建了一个对象：
    qr = qrcode.QRCode(version=5, error_correction=qrcode.constants.ERROR_CORRECT_H, box_size=8, border=4)
    # version：值为1~40的整数，控制二维码的大小（最小值是1，是个21×21的矩阵）
    # error_correction：控制二维码的错误纠正功能。可取值下列4个常量：
    '''
    qrcode.constants.ERROR_CORRECT_X：
        1. X=L时，大约7%或更少的错误能被纠正。 
        2. X=M（默认）时，大约15%或更少的错误能被纠正。
        3. X=Q时，25%以下的错误会被纠正。
        4. X=H时，大约30%或更少的错误能被纠正。
    '''
    # box_size：控制二维码中每个小格子包含的像素数。
    # border：控制边框（二维码与图片边界的距离）包含的格子数（默认为4)

    # 在此处向二维码中添加信息
    qr.add_data("https://www.ustb.edu.cn/")

    qr.make(fit=True)

    img = qr.make_image()
    # 二维码设置为彩色
    img = img.convert('RGBA')
    # 在此处向二维码中添加logo信息
    logo = Image.open("D:/ustbLOGO.png")
    # 二维码尺寸
    img_w, img_h = img.size
    # 默认LOGO最大设为图片的1/4
    factor = 4
    # 最大logo尺寸
    size_w = int(img_w / factor)
    size_h = int(img_h / factor)
    # logo的尺寸
    logo_w, logo_h = logo.size

    if logo_w > size_w or logo_h > size_h:
        logo_w = size_w
        logo_h = size_h
    logo = logo.resize((logo_w, logo_h), Image.ANTIALIAS).convert('RGBA')
    l_w = int((img_w - logo_w) / 2)
    l_h = int((img_h - logo_h) / 2)
    # 替换指定位置
    img.paste(logo, (l_w, l_h), logo)
    img.show()

    # 在此处向二维码中添加生成信息
    img.save('D:/北科大网址二维码.png')


def disQR():
    # 在此处添加需要识别的二维码信息
    qrcode_filename = "D:/test.jpg"
    qrcode_image = cv2.imread(qrcode_filename)
    qrCodeDetector = cv2.QRCodeDetector()
    data, bbox, straight_qrcode = qrCodeDetector.detectAndDecode(qrcode_image)

    print(data)

start = input('请输入您需要生成或识别二维码： ')
selection = input('生成请输1，识别请输2： ')
if selection == '1':
    creatQR();

elif selection == '2':
    disQR();
else:
    pass