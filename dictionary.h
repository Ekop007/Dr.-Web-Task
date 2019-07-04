#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <map>
#include <iostream>
#include <exception>

template<class TKey>
class NotFoundException : public std::exception
{
public:
     virtual const TKey& GetKey() const noexcept = 0;
};

template<class TKey>
class NotFoundExceptionImpl : public NotFoundException<TKey>
{
public:
    explicit NotFoundExceptionImpl(const TKey &k);
    const TKey& GetKey() const noexcept;

private:
    TKey key;
};

template<class TKey>
NotFoundExceptionImpl<TKey>::NotFoundExceptionImpl(const TKey &k)
{
    key = k;
    this->what() = "Element not found";
}

template<class TKey>
const TKey &NotFoundExceptionImpl<TKey>::GetKey() const noexcept
{
    return key;
}

template<class TKey, class TValue>
class Dictionary
{
public:
     virtual ~Dictionary() = default;

     virtual const TValue& Get(const TKey& key) const = 0;
     virtual void Set(const TKey& key, const TValue& value) = 0;
     virtual bool IsSet(const TKey& key) const = 0;
};

template<class TKey, class TValue>
class DictionaryImpl : public Dictionary<TKey, TValue>
{
public:
    ~DictionaryImpl();

    const TValue& Get(const TKey& key) const;
    void Set(const TKey& key, const TValue& value);
    bool IsSet(const TKey& key) const;

private:
    std::map<TKey, TValue> array;
};

template<class TKey, class TValue>
DictionaryImpl<TKey, TValue>::~DictionaryImpl()
{
    if (!array.empty())
    {
        array.clear();
    }
}


template<class TKey, class TValue>
const TValue &DictionaryImpl<TKey, TValue>::Get(const TKey &key) const
{
   if (array.count(key) > 0)
   {
       return array.at(key);
   }
   else
   {
       throw NotFoundExceptionImpl<TKey>(key);
   }
}

template<class TKey, class TValue>
void DictionaryImpl<TKey, TValue>::Set(const TKey &key, const TValue &value)
{
    array[key] = value;
}

template<class TKey, class TValue>
bool DictionaryImpl<TKey, TValue>::IsSet(const TKey &key) const
{
    if (array.find(key) == array.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

#endif // DICTIONARY_H
