/*
COutPoint主要用在交易的输出CTxIn中，用来确定当前输出的来源，
包括前一笔交易的hash，以及对应前一笔交易中的第几个输出的序列号。
*/
class COutPoint {
public:
	uint256 hash;//交易的hash
	uint32_t n;//对应的序列号

	COutPoint() { SetNull(); }
	COutPoint(uint256 hashIn,uint)
};