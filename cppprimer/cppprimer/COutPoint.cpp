/*
COutPoint��Ҫ���ڽ��׵����CTxIn�У�����ȷ����ǰ�������Դ��
����ǰһ�ʽ��׵�hash���Լ���Ӧǰһ�ʽ����еĵڼ�����������кš�
*/
class COutPoint {
public:
	uint256 hash;//���׵�hash
	uint32_t n;//��Ӧ�����к�

	COutPoint() { SetNull(); }
	COutPoint(uint256 hashIn,uint)
};