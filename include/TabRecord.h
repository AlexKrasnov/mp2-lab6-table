#pragma once
typedef int KeyType;
typedef char DataType;

class TabRecord
{
protected:
	KeyType key;
	DataType *data;
public:
	TabRecord();
	TabRecord(KeyType,DataType*);
	KeyType GetKey() const;
	DataType* GetData() const;
	TabRecord& operator=(const TabRecord&);
	virtual bool operator==(const TabRecord&) const;
	virtual bool operator!=(const TabRecord&) const;
	virtual bool operator>=(const TabRecord&) const;
	virtual bool operator<=(const TabRecord&) const;
	virtual bool operator>(const TabRecord&) const;
	virtual bool operator<(const TabRecord&) const;
};