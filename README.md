# Dr.-Web-Task
Необходимо реализовать класс контейнера, реализующий интерфейс 
Dictionary и способный выбросить исключение, реализующее интерфейс 
NotFoundException.
При разработке допускается использовать STL. Кроме этого, внутренняя 
реализация ничем не ограничена.

template<class TKey, class TValue>

class Dictionary
{

public: 

     virtual ~Dictionary() = default;
     virtual const TValue& Get(const TKey& key) const = 0;
     virtual void Set(const TKey& key, const TValue& value) = 0;
     virtual bool IsSet(const TKey& key) const = 0;
	
};


template<class TKey>
	
class NotFoundException : public std::exception

{

public:    

     virtual const TKey& GetKey() const noexcept = 0;
};
