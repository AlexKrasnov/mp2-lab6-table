#include "gtest.h"
#include "ScanTable.h"

TEST(Record, can_create_table)
{
	TabRecord *tab;
	ASSERT_NO_THROW(tab = new TabRecord(5, "abcd"));
}

TEST(Record, can_get_key)
{
	TabRecord *tab = new TabRecord(5, "abcd");
	int k;
	ASSERT_NO_THROW(k = tab->GetKey());
}

TEST(Record, can_get_data)
{
	TabRecord *tab = new TabRecord(5, "abcd");
	char *d;
	ASSERT_NO_THROW(d = tab->GetData());
}

TEST(Record, get_key_correctly)
{
	TabRecord *tab = new TabRecord(5, "abc");
	int k = tab->GetKey();
	EXPECT_EQ(5, k);
}

TEST(Record, get_data_correctly)
{
	TabRecord *tab = new TabRecord(5, "abc");
	char *d = tab->GetData();
	EXPECT_EQ("abc", d);
}

TEST(Record, can_assign)
{
	TabRecord *tab1 = new TabRecord(5, "abc");
	TabRecord *tab2 = new TabRecord(7, "abcde");
	ASSERT_NO_THROW(tab1=tab2);
}

TEST(Record, assign_correctly)
{
	TabRecord *tab1 = new TabRecord(5, "abc");
	TabRecord *tab2 = new TabRecord(7, "abcde");
	tab1=tab2;
	EXPECT_TRUE(tab1->GetKey()==7 && tab1->GetData()=="abcde");
}

TEST(Scantable, can_create_table_by_size)
{
	ASSERT_NO_THROW(ScanTable *tab = new ScanTable(5));
}

TEST(Scantable, can_create_table)
{
	ASSERT_NO_THROW(ScanTable *tab = new ScanTable());
}

TEST(Scantable, can_copy_table)
{
	ScanTable s(2);
	ASSERT_NO_THROW(ScanTable s1(s));
}

TEST(Scantable, can_find)
{
	ScanTable *s = new ScanTable();
	s->Find(1);
	s->Find(5);
	TabRecord* t;
	ASSERT_NO_THROW(t = s->Find(5));
}

TEST(Scantable, can_insert)
{
	ScanTable s(5);
	ASSERT_NO_THROW(s.Ins(3, "abc"));
}

TEST(Scantable, insert_correctly)
{
	ScanTable s(5);
	ASSERT_NO_THROW(s.Ins(3, "abc"));
	EXPECT_TRUE(s.Find(3)->GetData()=="abc");
}

TEST(Scantable, insert_correctly_in_too_key)
{
	ScanTable *s = new ScanTable(5);
	s->Ins(1, "a");
	s->Ins(1, "b");
	EXPECT_TRUE(s->Find(1)->GetData()=="b");
}
/*
TEST(Scantable, throw_when_insert_in_full_tab)
{
	ScanTable s(1);
	s.Ins(3, "abc");
	ASSERT_ANY_THROW(s.Ins(5, "abc"));
}
*/
TEST(Scantable, can_delete)
{
	ScanTable *s = new ScanTable(5);
	s->Ins(1, "a");
	s->Ins(2, "b");
	ASSERT_NO_THROW(s->Del(1));
}

TEST(Scantable, delete_correctly)
{
	ScanTable *s = new ScanTable(5);
	s->Ins(1, "a");
	s->Ins(2, "b");
	s->Del(1);
	EXPECT_TRUE(s->Find(1)==NULL);
}
/*
TEST(Scantable, throw_when_dell_from_empty_tab)
{
	ScanTable s(1);
	s.Ins(3, "abc");
	s.Del(3);
	ASSERT_ANY_THROW(s.Del(3));
}
*/