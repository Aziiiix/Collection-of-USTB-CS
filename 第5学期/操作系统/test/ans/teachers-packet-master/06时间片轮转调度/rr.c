/*
�ṩ��ʾ��������Ϊ�˲���һ��������߽���һ�����ԣ�����������
�ȫ�ı���ʵ������˲�Ӧ��Ӧ�ó������վ��ʹ�ø�ʾ�����롣��
�ڳ�����ʾ�������Ԥ����;�����ʹ������ɵ�żȻ��̷�����ʧ��
����Ӣ��ʱ���Ƽ����޹�˾���е��κ����Ρ�
*/

VOID
PspRoundRobin(
	VOID
	)
{
	//
	// ֻ���ڵ�ǰ�̣߳����ж��̣߳��Դ�������״̬ʱ���Ž���ʱ��Ƭ��ת���ȡ�
	// �����ǰ�̱߳��������Ͳ���Ҫ����ʱ��Ƭ��ת���ȡ�
	//
	if (NULL != PspCurrentThread && Running == PspCurrentThread->State) {

		//
		// ����ǰ�����̵߳�ʣ��ʱ��Ƭ���� 1��
		//
		PspCurrentThread->RemainderTicks--;
		
		//
		// ���ʣ��ʱ��Ƭ��Ϊ 0 ��ִ�����²�����
		// 1. ����Ϊ��ǰ�̷߳���ʱ��Ƭ��
		// 2. ������ں͵�ǰ�߳����ȼ���ͬ�ľ����̣߳��ͽ���ǰ�߳�ת�����״̬��
		//
		if (0 == PspCurrentThread->RemainderTicks) {

			PspCurrentThread->RemainderTicks = TICKS_OF_TIME_SLICE;

			if (BIT_TEST(PspReadyBitmap, PspCurrentThread->Priority)) {
			
				//
				// PspReadyThread �����Ὣ�̲߳��������ȼ���Ӧ�ľ������еĶ�β��
				// �����þ���λͼ�ж�Ӧ��λ������̵߳�״̬�޸�Ϊ����״̬��
				//
				PspReadyThread(PspCurrentThread);
			}
		}
	}
}
