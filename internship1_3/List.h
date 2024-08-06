#pragma once
#include<string>
#include <cassert>

///@brief 双方向リストのクラスです。
template<typename DataType>
class List
{
private:
    ///@brief リストのノードです。
    struct Node
    {
        //! データ
        DataType data;

        //! 前のノードのポインタ
        Node* front = nullptr;

        //! 後ろのノードのポインタ
        Node* back = nullptr;
    };

public:

    ///@brief リストのコンストイテレーターです。
    class ConstIterator
    {
    public:

        ConstIterator() = default;

        ConstIterator(Node* ptr,const List* parent);

        ConstIterator(const ConstIterator& iterator);

        ConstIterator operator =(const ConstIterator& iterator);

        const DataType& operator *()const;

        ConstIterator& operator --();

        ConstIterator& operator ++();

        ConstIterator operator --(int);

        ConstIterator operator ++(int);

        bool operator !=(ConstIterator right)const;

        bool operator ==(ConstIterator right)const;

    protected:

        //! ノードのポインタ
        Node* m_element = nullptr;

        //! リストのポインタ
        const List* m_parent = nullptr;

        friend List;
    };

    ///@brief リストのイテレーターです。
    class Iterator :public ConstIterator
    {
    public:
        using ConstIterator::ConstIterator;

        DataType& operator *();
    };

    ///@brief Listのコンストラクタです。
    List();

    ///@brief Listのデストラクタです。
    ~List();

    ///@brief リストの先頭イテレーターを返します
    ///@return 先頭イテレーター
    Iterator begin();

    ///@brief リストの末尾イテレーターを返します
    ///@return 末尾イテレーター
    Iterator end();

    ///@brief リストの先頭コンストイテレーターを返します
    ///@return 先頭コンストイテレーター
    ConstIterator begin()const;

    ///@brief リストの末尾コンストイテレーターを返します
    ///@return 末尾コンストイテレーター
    ConstIterator end()const;

    ///@brief リストの先頭コンストイテレーターを返します
    ///@return 先頭イテレーター
    ConstIterator constBegin() const;

    ///@brief リストの末尾コンストイテレーターを返します
    ///@return 末尾イテレーター
    ConstIterator constEnd() const;

    ///@brief リストの長さを返します
    ///@return リストの長さ
    size_t size()const;

    ///@brief リストに新たな要素を挿入します。
    ///@param iterator 追加する位置のイテレーター
    ///@param addData 追加するデータ
    ///@return 追加に成功したらtrue 失敗したらfalse
    bool insert(ConstIterator iterator, const DataType& addData);

    ///@brief リストの要素を削除します。
    ///@param iterator 削除する位置のイテレーター
    ///@return 削除に成功したらtrue 失敗したらfalse
    bool remove(ConstIterator iterator);

    ///@brief リストの末尾に要素を追加します。
    ///@param addData 追加するデータ
    void add(const DataType& addData);

private:
    //! 番兵のポインタ
    Node* m_sentinel;

    //! リストの長さ
    size_t m_size = 0;
};

#include"List.inl"
