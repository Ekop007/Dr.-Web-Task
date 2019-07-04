#include "dictionary.h"

using namespace std;

int main()
{
    DictionaryImpl<int, char> dic;
    dic.Set(1, 'a');
    dic.Set(2, 'b');
    std::cout << dic.Get(1) << std::endl;
    std::cout << dic.Get(2) << std::endl;
    try
    {
        std::cout << dic.Get(3) << std::endl;
    }
    catch (NotFoundExceptionImpl<int> &ex)
    {
        std::cout << "Not found key " << ex.GetKey() << std::endl;
    }
    return 0;
}
