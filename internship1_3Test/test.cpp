#include "pch.h"
#include"../internship1_3/List.h"
#include"../internship1_3/Grades.h"

///@brief Listの内容が正解と等しいか確認します
///@param ans 正解をvectorとして渡します
///@param list 内容が正しいか調べたいListを渡します
void CheckValue(const std::vector<Grades>& ans, const List<Grades>& list)
{
	EXPECT_TRUE(ans.size() == list.size());

	size_t i = 0;
	for (const auto& grades :list )
	{

		EXPECT_EQ(grades, ans[i]);

		++i;
	}
}

//ID:8 データ数の取得 constのメソッドであるか
#if 0
TEST(TestListSize, IsConst)
{
	const List<Grades> list;
	list.size();
}
#endif

//ID:15 データの挿入 非constのメソッドであるか
#if 0
TEST(TestListInsert, IsNotConst)
{
	const List<Grades> list;
	list.insert(list.begin(), Grades{ 0,"hoge" });
}
#endif

//ID:22 データの削除 非constのメソッドであるか
#if 0
TEST(TestListRemove, IsNotConst)
{
	const List<Grades> list;
	list.remove(list.begin());
}
#endif

//ID:28 先頭イテレータの取得 constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
#if 0
TEST(TestListBegin, IsNotConst)
{
	const List<Grades> list;
	List<Grades>::Iterator it=list.begin();
}
#endif

//ID:34 先頭コンストイテレータの取得 constのメソッドであるか
#if 0
TEST(TestListConstBegin, IsConst)
{
	const List<Grades> list;
	list.constBegin();
}
#endif

//ID:40 末尾イテレータの取得 constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
#if 0
TEST(TestListEnd, IsNotConst)
{
	const List<Grades> list;
	List<Grades>::Iterator it = list.end();
}
#endif

//ID:46 末尾コンストイテレータの取得 constのメソッドであるか
#if 0
TEST(TestListConstEnd, IsConst)
{
	const List<Grades> list;
	list.constEnd();
}
#endif

//ID:2 イテレータの指す要素を取得する ConstIteratorから取得した要素に対して、値の代入が行えないかをチェック
#if 0
TEST(TestConstIteratorGetElement, NotAssignable)
{
	const List<Grades> list;
	auto it=list.constBegin();
	(*it) = Grades{ 0,"hoge" };
}
#endif

//ID:17 ConstIteratorから、Iteratorのコピーが作成されないかをチェック
#if 0
TEST(TestConstIteratorCopy, CanNotCopyToIterator)
{
	List<Grades> list;
	auto it=list.begin();
	auto constIt=list.constBegin();
	it = constIt;
}
#endif

//ID:19 イテレータの代入を行う IteratorにConstIteratorを代入できない事をチェック
#if 0
TEST(TestConstIteratorAssign, CanNotAssignToIterator)
{
	List<Grades> list;
	auto it = list.begin();
	auto constIt = list.constBegin();
	it = constIt;
}
#endif





//リストのテスト

//データ数の取得

//リストが空である場合の戻り値
TEST(TestListSize, Empty) 
{
	List<Grades> list;
	EXPECT_EQ(0, list.size());
}

//リスト末尾への挿入を行った際の戻り値
TEST(TestListSize, Add)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	EXPECT_EQ(1, list.size());
}

//データの挿入を行った際の戻り値
TEST(TestListSize, Insert)
{
	List<Grades> list;
	list.insert(list.begin(), Grades{ 0,"hoge" });
	EXPECT_EQ(1, list.size());
}

//データの挿入に失敗した際の戻り値
TEST(TestListSize, FailInsert)
{
	List<Grades> list;
	list.insert(List<Grades>::Iterator{}, Grades{ 0,"hoge" });
	EXPECT_EQ(0, list.size());
}

//データの削除を行った際の戻り値
TEST(TestListSize, Remove)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.remove(list.begin());
	EXPECT_EQ(0, list.size());
}

//データの削除が失敗した際の戻り値
TEST(TestListSize, FailRemove)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.remove(List<Grades>::Iterator{});
	EXPECT_EQ(1, list.size());
}

//リストが空である場合に、データの削除を行った際の戻り値
TEST(TestListSize, RemoveWhenEmpty)
{
	List<Grades> list;
	list.remove(list.begin());
	EXPECT_EQ(0, list.size());
}

//データの挿入

//リストが空である場合に、挿入した際の挙動
TEST(TestListInsert, Empty) 
{

	//先頭イテレータで挿入
	{
		List<Grades> list;
		EXPECT_TRUE(list.insert(list.begin(), Grades{ 0,"hoge" }));
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}

	//末尾イテレータで挿入
	{
		List<Grades> list;
		EXPECT_TRUE(list.insert(list.end(), Grades{ 0,"hoge" }));
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}
}

//リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動
TEST(TestListInsert, InsertBegin)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.insert(list.begin(), Grades{ 2,"piyo" }));
	CheckValue({ Grades{ 2,"piyo" },Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
}

//リストに複数の要素がある場合に、末尾イテレータを渡して、挿入した際の挙動
TEST(TestListInsert, InsertEnd)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.insert(list.end(), Grades{ 2,"piyo" }));
	CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
}

//リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動
TEST(TestListInsert, InsertCenter)
{

	//先頭に追加
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		EXPECT_TRUE(list.insert(list.begin(), Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 2,"piyo" },Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}

	//末尾に追加
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		EXPECT_TRUE(list.insert(list.end(), Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}

	//途中に追加
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		auto iterator = list.begin();
		++iterator;
		EXPECT_TRUE(list.insert(iterator, Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 0,"hoge" }, Grades{ 2,"piyo" },Grades{ 1,"fuga" } }, list);
	}
}

//ConstIteratorを指定して挿入を行った際の挙動
TEST(TestListInsert, InsertConstIterator)
{

	//先頭に追加
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		EXPECT_TRUE(list.insert(list.constBegin(), Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 2,"piyo" },Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}

	//末尾に追加
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		EXPECT_TRUE(list.insert(list.constEnd(), Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}
	//途中に追加
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		auto iterator = list.constBegin();
		++iterator;
		EXPECT_TRUE(list.insert(iterator, Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 0,"hoge" }, Grades{ 2,"piyo" },Grades{ 1,"fuga" } }, list);
	}
}

//不正なイテレータを渡して、挿入した場合の挙動
TEST(TestListInsert, InsertInvalidIterator)
{
	//参照の無いイテレーター
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		EXPECT_FALSE(list.insert(List<Grades>::Iterator{}, Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}

	//別のリストのイテレーター
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });

		List<Grades> otherList;
		otherList.add(Grades{ 2,"piyo" });

		EXPECT_FALSE(list.insert(otherList.begin(), Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}

}


//データの削除

//リストが空である場合に、削除を行った際の挙動
TEST(TestListRemove, Empty)
{
	//先頭イテレーターで削除
	{
		List<Grades> list;
		EXPECT_FALSE(list.remove(list.begin()));
		CheckValue({ }, list);
	}

	//末尾イテレーターで削除
	{
		List<Grades> list;
		EXPECT_FALSE(list.remove(list.end()));
		CheckValue({ }, list);
	}
}


//リストに複数の要素がある場合に、先頭イテレータを渡して、削除した際の挙動
TEST(TestListRemove, RemoveBegin)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.remove(list.begin()));
	CheckValue({ Grades{ 1,"fuga" } }, list);
}

//リストに複数の要素がある場合に、末尾イテレータを渡して、削除した際の挙動
TEST(TestListRemove, RemoveEnd) 
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_FALSE(list.remove(list.end()));
	CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
}

//リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動
TEST(TestListRemove, RemoveCenter) 
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });

	auto iterator = list.begin();
	++iterator;
	EXPECT_TRUE(list.remove(iterator));
	CheckValue({ Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
}

//ConstIteratorを指定して削除を行った際の挙動
TEST(TestListRemove, RemoveConstIterator)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });

	auto iterator = list.constBegin();
	++iterator;
	EXPECT_TRUE(list.remove(iterator));
	CheckValue({ Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
}

//不正なイテレータを渡して、削除した場合の挙動
TEST(TestListRemove, RemoveInvalidIterator)
{
	//参照の無いイテレーター
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });

		EXPECT_FALSE(list.remove(List<Grades>::Iterator{}));
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}

	//他のリストのイテレーター
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });

		List<Grades> otherList;
		otherList.add(Grades{ 2,"piyo" });

		EXPECT_FALSE(list.remove(otherList.begin()));
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}
}

//先頭イテレータの取得

//リストが空である場合に、呼び出した際の挙動
TEST(TestListBegin, Empty)
{
	List<Grades> list;
	EXPECT_EQ(list.begin(),list.end());
}

//リストに要素が一つある場合に、呼び出した際の挙動
TEST(TestListBegin, OneElement)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
}

//リストに二つ以上の要素がある場合に、呼び出した際の挙動
TEST(TestListBegin, MultipleElements)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
}

//データの挿入を行った後に、呼び出した際の挙動
TEST(TestListBegin, AfterInsert)
{
	//先頭に挿入
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.begin(), Grades{ 2,"piyo" });
		EXPECT_TRUE((*list.begin() == Grades{ 2,"piyo" }));
	}

	//末尾に挿入
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.end(), Grades{ 2,"piyo" });
		EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
	}

	//途中に挿入
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		auto iterator = list.begin();
		++iterator;
		list.insert(iterator, Grades{ 2,"piyo" });
		EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
	}
}

//データの削除を行った後に、呼び出した際の挙動
TEST(TestListBegin, AfterRemove)
{
	//先頭を削除
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.remove(list.begin());
		EXPECT_TRUE((*list.begin() == Grades{ 1,"fuga" }));
	}

	//末尾を削除
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto it = list.end();
		--it;
		list.remove(it);
		EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
	}

	//途中を削除
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto iterator = list.begin();
		++iterator;
		list.remove(iterator);
		EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
	}
}


//先頭コンストイテレータの取得

//リストが空である場合に、呼び出した際の挙動
TEST(TestListConstBegin, Empty) 
{
	List<Grades> list;
	EXPECT_EQ(list.constBegin(), list.constEnd());
}

//リストに要素が一つある場合に、呼び出した際の挙動
TEST(TestListConstBegin, OneElement)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}

//リストに二つ以上の要素がある場合に、呼び出した際の挙動
TEST(TestListConstBegin, MultipleElements)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}

//データの挿入を行った後に、呼び出した際の挙動
TEST(TestListConstBegin, AfterInsert) 
{
	//先頭に挿入
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.begin(), Grades{ 2,"piyo" });
		EXPECT_TRUE((*list.constBegin() == Grades{ 2,"piyo" }));
	}

	//末尾に挿入
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.end(), Grades{ 2,"piyo" });
		EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
	}

	//途中に挿入 
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		auto iterator = list.begin();
		++iterator;
		list.insert(iterator, Grades{ 2,"piyo" });
		EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
	}

}


//データの削除を行った後に、呼び出した際の挙動
TEST(TestListConstBegin, AfterRemove) 
{
	//先頭を削除
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.remove(list.begin());
		EXPECT_TRUE((*list.constBegin() == Grades{ 1,"fuga" }));
	}

	//末尾を削除
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto it = list.end();
		--it;
		list.remove(it);
		EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
	}

	//途中を削除
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto iterator = list.begin();
		++iterator;
		list.remove(iterator);
		EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
	}
}


//末尾イテレータの取得

//リストが空である場合に、呼び出した際の挙動
TEST(TestListEnd, Empty) 
{
	List<Grades> list;
	EXPECT_EQ(list.end(),list.begin());
}

//リストに要素が一つある場合に、呼び出した際の挙動
TEST(TestListEnd, OneElement)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 0,"hoge" }));
}

//リストに二つ以上の要素がある場合に、呼び出した際の挙動
TEST(TestListEnd, MultipleElements)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//データの挿入を行った後に、呼び出した際の挙動
TEST(TestListEnd, AfterInsert) 
{
	//先頭に挿入
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.begin(), Grades{ 2,"piyo" });
		auto it = list.end();
		--it;
		EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
	}

	//末尾に挿入
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.end(), Grades{ 2,"piyo" });
		auto it = list.end();
		--it;
		EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
	}

	//途中に挿入
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		auto iterator = list.begin();
		++iterator;
		list.insert(iterator, Grades{ 2,"piyo" });
		auto it = list.end();
		--it;
		EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
	}
}


//データの削除を行った後に、呼び出した際の挙動
TEST(TestListEnd, AfterRemove)
{

	//先頭を削除
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.remove(list.begin());
		auto it = list.end();
		--it;
		EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
	}

	//末尾を削除
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto endIt = list.end();
		--endIt;
		list.remove(endIt);
		auto it = list.end();
		--it;
		EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
	}

	//途中を削除
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto iterator = list.begin();
		++iterator;
		list.remove(iterator);
		auto it = list.end();
		--it;
		EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
	}
}

//末尾コンストイテレータの取得

//リストが空である場合に、呼び出した際の挙動
TEST(TestListConstEnd, Empty)
{
	List<Grades> list;
	EXPECT_EQ(list.constEnd(),list.constBegin());
}

//リストに要素が一つある場合に、呼び出した際の挙動
TEST(TestListConstEnd, OneElement)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 0,"hoge" }));
}

//リストに二つ以上の要素がある場合に、呼び出した際の挙動
TEST(TestListConstEnd, MultipleElements)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//データの挿入を行った後に、呼び出した際の挙動
TEST(TestListConstEnd, AfterInsert) 
{
	//先頭に挿入
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.begin(), Grades{ 2,"piyo" });
		auto it = list.constEnd();
		--it;
		EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
	}

	//後方に挿入
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.end(), Grades{ 2,"piyo" });
		auto it = list.constEnd();
		--it;
		EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
	}

	//途中に挿入
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		auto iterator = list.begin();
		++iterator;
		list.insert(iterator, Grades{ 2,"piyo" });
		auto it = list.constEnd();
		--it;
		EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
	}
}

//データの削除を行った後に、呼び出した際の挙動
TEST(TestListConstEnd, AfterRemove)
{
	//先頭を削除
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.remove(list.begin());
		auto it = list.constEnd();
		--it;
		EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
	}

	//末尾を削除
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto endIt = list.end();
		--endIt;
		list.remove(endIt);
		auto it = list.constEnd();
		--it;
		EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
	}

	//途中を削除
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto iterator = list.begin();
		++iterator;
		list.remove(iterator);
		auto it = list.constEnd();
		--it;
		EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
	}
}

//イテレーターのテスト

#ifdef _DEBUG

//イテレータの指す要素を取得する

//リストの参照がない状態で呼び出した際の挙動
TEST(TestIteratorGetElement, NoReferences)
{
	List<Grades>::Iterator it;
	EXPECT_DEATH((*it).score, ".*");
}

//Iteratorから取得した要素に対して、値の代入が行えるかをチェック
TEST(TestIteratorGetElement, AssignValue)
{

	List<Grades> list;
	list.add({ 0,"hoge" });

	auto it = list.begin();
	(*it) = Grades{ 1,"fuga" };

	EXPECT_TRUE(((*it) == Grades{ 1,"fuga" }));
}

//リストが空の際の、先頭イテレータに対して呼び出した際の挙動
TEST(TestIteratorGetElement, BeginIteratorWhenEmpty)
{
	List<Grades> list;
	EXPECT_DEATH((*list.begin()).score, ".*");
}

//末尾イテレータに対して呼び出した際の挙動
TEST(TestIteratorGetElement, EndIterator)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_DEATH((*list.end()).score, ".*");
}


//イテレータをリストの末尾に向かって一つ進める

//リストの参照がない状態で呼び出した際の挙動
TEST(TestIteratorIncrement, NoReferences)
{
	List<Grades>::Iterator it;
	EXPECT_DEATH(++it, ".*");
}

//リストが空の際の、先頭イテレータに対して呼び出した際の挙動
TEST(TestIteratorIncrement, BeginIteratorWhenEmpty)
{
	List<Grades> list;
	auto it = list.begin();
	EXPECT_DEATH(++it, ".*");
}

//末尾イテレータに対して呼び出した際の挙動
TEST(TestIteratorIncrement, EndIterator)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.end();
	EXPECT_DEATH(++it, ".*");
}

#endif

//リストに二つ以上の要素がある場合に呼び出した際の挙動
TEST(TestIteratorIncrement, MultipleElements)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });
	list.add({ 2,"piyo" });

	std::vector<Grades>ans{ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } };

	size_t i = 0;
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		EXPECT_TRUE((*it == ans[i]));
		++i;
	}
}

//前置インクリメントを行った際の挙動(++演算子オーバーロードで実装した場合)
TEST(TestIteratorIncrement, PrefaceIncrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	EXPECT_TRUE((*(++it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

////後置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
TEST(TestIteratorIncrement, PostfixIncrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	EXPECT_TRUE((*(it++) == Grades{ 0,"hoge" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}


#ifdef _DEBUG

//イテレータをリストの先頭に向かって一つ進める

//リストの参照がない状態で呼び出した際の挙動
TEST(TestIteratorDecrement, NoReferences)
{
	List<Grades>::Iterator it;
	EXPECT_DEATH(--it, ".*");
}

//リストが空の際の、末尾イテレータに対して呼び出した際の挙動
TEST(TestIteratorDecrement, EndIteratorWhenEmpty)
{
	List<Grades> list;
	auto it = list.end();
	EXPECT_DEATH(--it, ".*");
}

//先頭イテレータに対して呼び出した際の挙動
TEST(TestIteratorDecrement, BeginIterator)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.begin();
	EXPECT_DEATH(--it, ".*");
}

#endif

//リストに二つ以上の要素がある場合に呼び出した際の挙動
TEST(TestIteratorDecrement, MultipleElements)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });
	list.add({ 2,"piyo" });

	std::vector<Grades>ans{ Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } };

	auto it = list.end();

	for (size_t i=0;i< list.size();++i)
	{
		--it;
		EXPECT_TRUE((*it == ans[i]));
	}

}

//前置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合)
TEST(TestIteratorDecrement, PrefixDecrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.end();
	EXPECT_TRUE((*(--it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//後置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
TEST(TestIteratorDecrement, PostfixDecrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.end();
	it--;
	EXPECT_TRUE(((*(it--)) == Grades{ 1,"fuga" }));
	EXPECT_TRUE(((*it) == Grades{ 0,"hoge" }));
}



//イテレータのコピーを行う


//コピーコンストラクト後の値がコピー元と等しいことをチェック
TEST(TestIteratorCopy, CheckCopy) 
{
	List<Grades> list;
	list.add({ 0,"hoge" });

	auto it = list.begin();

	auto itCopy = it;

	EXPECT_TRUE(itCopy == it);
}

//イテレータの代入を行う

//代入後の値がコピー元と等しいことをチェック
TEST(TestIteratorAssign, CheckAssign)
{
	List<Grades> list;
	list.add({ 0,"hoge" });

	auto it = list.begin();
	List<Grades>::Iterator itCopy;
	itCopy = it;

	EXPECT_TRUE(itCopy == it);
}

//二つのイテレータが同一のものであるか、比較を行う


//リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
TEST(TestIteratorEqual, CompareBeginAndEndWhenEmpty)
{
	List<Grades> list;
	EXPECT_EQ(list.begin(),list.end());
}

//同一のイテレータを比較した際の挙動
TEST(TestIteratorEqual, CompareSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	EXPECT_EQ(list.begin(),list.begin());
}

//異なるイテレータを比較した際の挙動
TEST(TestIteratorEqual, CompareNotSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_FALSE(itA == itB);
}



//二つのイテレータが異なるものであるか、比較を行う


//リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
TEST(TestIteratorNotEqual, CompareBeginAndEndWhenEmpty)
{
	List<Grades> list;
	EXPECT_FALSE(list.begin() != list.end());
}

//同一のイテレータを比較した際の挙動
TEST(TestIteratorNotEqual, CompareSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	EXPECT_FALSE(list.begin() != list.begin());
}

//異なるイテレータを比較した際の挙動
TEST(TestIteratorNotEqual, CompareNotSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_TRUE(itA != itB);
}



//コンストイテレーターのテスト

#ifdef _DEBUG

//イテレータの指す要素を取得する

//リストの参照がない状態で呼び出した際の挙動
TEST(TestConstIteratorGetElement, NoReferences)
{
	List<Grades>::ConstIterator it;
	EXPECT_DEATH((*it).score, ".*");
}

//リストが空の際の、先頭イテレータに対して呼び出した際の挙動
TEST(TestConstIteratorGetElement, BeginIteratorWhenEmpty)
{
	List<Grades> list;
	EXPECT_DEATH((*list.constBegin()).score, ".*");
}

//末尾イテレータに対して呼び出した際の挙動
TEST(TestConstIteratorGetElement, EndIterator)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_DEATH((*list.constEnd()).score, ".*");
}


//イテレータをリストの末尾に向かって一つ進める


//リストの参照がない状態で呼び出した際の挙動
TEST(TestConstIteratorIncrement, NoReferences)
{
	List<Grades>::ConstIterator it;
	EXPECT_DEATH(++it, ".*");
}

//リストが空の際の、先頭イテレータに対して呼び出した際の挙動
TEST(TestConstIteratorIncrement, BeingIteratorWhenEmpty)
{
	List<Grades> list;
	auto it = list.constBegin();
	EXPECT_DEATH(++it, ".*");
}

//末尾イテレータに対して呼び出した際の挙動
TEST(TestConstIteratorIncrement, EndIterator)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.constEnd();
	EXPECT_DEATH(++it, ".*");
}

#endif


//リストに二つ以上の要素がある場合に呼び出した際の挙動
TEST(TestConstIteratorIncrement, MultipleElements)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	++it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//前置インクリメントを行った際の挙動(++演算子オーバーロードで実装した場合)
TEST(TestConstIteratorIncrement, PrefixIncrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	EXPECT_TRUE((*(++it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

////後置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
TEST(TestConstIteratorIncrement, PostfixIncrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	EXPECT_TRUE((*(it++) == Grades{ 0,"hoge" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}


#ifdef _DEBUG

//イテレータをリストの先頭に向かって一つ進める

//リストの参照がない状態で呼び出した際の挙動
TEST(TestConstIteratorDecrement, NoReferences)
{
	List<Grades>::ConstIterator it;
	EXPECT_DEATH(--it, ".*");
}

//リストが空の際の、先頭イテレータに対して呼び出した際の挙動
TEST(TestConstIteratorDecrement, BeingIteratorWhenEmpty)
{
	List<Grades> list;
	auto it = list.constBegin();
	EXPECT_DEATH(--it, ".*");
}

//先頭イテレータに対して呼び出した際の挙動
TEST(TestConstIteratorDecrement, BeingIterator)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.constBegin();
	EXPECT_DEATH(--it, ".*");
}

#endif

//リストに二つ以上の要素がある場合に呼び出した際の挙動
TEST(TestConstIteratorDecrement, MultipleElements)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//前置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合)
TEST(TestConstIteratorDecrement, PrefixDecrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constEnd();
	EXPECT_TRUE((*(--it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

////後置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
TEST(TestConstIteratorDecrement, PostfixDecrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constEnd();
	it--;
	EXPECT_TRUE(((*(it--)) == Grades{ 1,"fuga" }));
	EXPECT_TRUE(((*it) == Grades{ 0,"hoge" }));
}




//イテレータのコピーを行う

//コピーコンストラクト後の値がコピー元と等しいことをチェック
TEST(TestConstIteratorCopy, CheckCopy)
{
	List<Grades> list;
	list.add({ 0,"hoge" });

	auto it = list.constBegin();

	auto itCopy = it;

	EXPECT_TRUE(itCopy == it);
}


//イテレータの代入を行う

//代入後の値がコピー元と等しいことをチェック
TEST(TestConstIteratorAssign, CheckAssign)
{
	List<Grades> list;
	list.add({ 0,"hoge" });

	auto it = list.constBegin();
	List<Grades>::ConstIterator itCopy;
	itCopy = it;

	EXPECT_TRUE(itCopy == it);
}


//二つのイテレータが同一のものであるか、比較を行う


//リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
TEST(TestConstIteratorEqual, CompareBeginAndEndWhenEmpty)
{
	List<Grades> list;
	EXPECT_TRUE(list.constBegin() == list.constEnd());
}

//同一のイテレータを比較した際の挙動
TEST(TestConstIteratorEqual, CompareSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	EXPECT_TRUE(list.constBegin() == list.constBegin());
}

//異なるイテレータを比較した際の挙動
TEST(TestConstIteratorEqual, CompareNotSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_FALSE(itA == itB);
}



//二つのイテレータが異なるものであるか、比較を行う


//リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
TEST(TestConstIteratorNotEqual, CompareBeginAndEndWhenEmpty)
{
	List<Grades> list;
	EXPECT_FALSE(list.constBegin() != list.constEnd());
}

//同一のイテレータを比較した際の挙動
TEST(TestConstIteratorNotEqual, CompareSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	EXPECT_FALSE(list.constBegin() != list.constBegin());
}

//異なるイテレータを比較した際の挙動
TEST(TestConstIteratorNotEqual, CompareNotSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_TRUE(itA != itB);
}


