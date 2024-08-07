#include "pch.h"
#include"../internship1_3/List.h"
#include"../internship1_3/Grades.h"
#include"manualTest.h"

//ID:8 データ数の取得 constのメソッドであるか
TEST(TestListSize, IsConst)
{
#ifdef TEST_LIST_SIZE_IS_CONST
	const List<Grades> list;
	list.size();
#endif
}

//ID:15 データの挿入 非constのメソッドであるか
TEST(TestListInsert, IsNotConst)
{
#ifdef TEST_LIST_IMSERT_IS_NOT_CONST
	const List<Grades> list;
	list.insert(list.begin(), Grades{ 0,"hoge" });
#endif
}

//ID:22 データの削除 非constのメソッドであるか
TEST(TestListRemove, IsNotConst)
{
#ifdef TEST_LIST_REMOVE_IS_NOT_CONST
	const List<Grades> list;
	list.remove(list.begin());
#endif
}

//ID:28 先頭イテレータの取得 constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
TEST(TestListBegin, IsNotConst)
{
#ifdef TEST_LIST_BEGIN_IS_NOT_CONST
	const List<Grades> list;
	List<Grades>::Iterator it = list.begin();
#endif
}

//ID:34 先頭コンストイテレータの取得 constのメソッドであるか
TEST(TestListConstBegin, IsConst)
{
#ifdef TEST_LIST_CONSTBEGIN_IS_CONST
	const List<Grades> list;
	list.constBegin();
#endif
}

//ID:40 末尾イテレータの取得 constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
TEST(TestListEnd, IsNotConst)
{
#ifdef TEST_LIST_END_IS_NOT_CONST
	const List<Grades> list;
	List<Grades>::Iterator it = list.end();
#endif
}

//ID:46 末尾コンストイテレータの取得 constのメソッドであるか
TEST(TestListConstEnd, IsConst)
{
#ifdef TEST_LIST_CONST_END_IS_CONST
	const List<Grades> list;
	list.constEnd();
#endif
}

//ID:2 イテレータの指す要素を取得する ConstIteratorから取得した要素に対して、値の代入が行えないかをチェック
TEST(TestConstIteratorGetElement, NotAssignable)
{
#ifdef TEST_CONST_ITERATOR_GET_ELEMENT_NOT_ASSIGNABLE
	const List<Grades> list;
	auto it = list.constBegin();
	(*it) = Grades{ 0,"hoge" };
#endif
}

//ID:17 ConstIteratorから、Iteratorのコピーが作成されないかをチェック
TEST(TestConstIteratorCopy, CanNotCopyToIterator)
{
#ifdef TEST_CONST_ITERATOR_COPY_CAN_NOT_COPY_TO_ITERATOR
	List<Grades> list;
	auto constIt = list.constBegin();
	List<Grades>::Iterator it = constIt;
#endif
}

//ID:19 イテレータの代入を行う IteratorにConstIteratorを代入できない事をチェック
TEST(TestConstIteratorAssign, CanNotAssignToIterator)
{
#ifdef TEST_CONST_ITERATOR_ASSIGN_CAN_NOT_ASSIGN_TO_ITERATOR
	List<Grades> list;
	auto it = list.begin();
	auto constIt = list.constBegin();
	it = constIt;
#endif
}

