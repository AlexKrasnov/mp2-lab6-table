#pragma once
typedef int KeyType;
typedef char DataType;

class TabRecord
{
protected:
	KeyType key;
	DataType *data;
public:
	TabRecord(KeyType,DataType*);
	KeyType GetKey() const;
	DataType* GetData() const;
	TabRecord& operator=(const TabRecord&);
	bool operator==(const TabRecord&) const;
	bool operator!=(const TabRecord&) const;
	bool operator>=(const TabRecord&) const;
	bool operator<=(const TabRecord&) const;
	bool operator>(const TabRecord&) const;
	bool operator<(const TabRecord&) const;
};