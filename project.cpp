// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <type_traits>

template <typename T>
class custom {
    std::vector<T> storage;
public:
    custom(std::vector<T> arr) : storage{arr} {}
    
    auto get_custiomized_sub(std::vector<T> array)
    {
        auto sub =0;
        int size = sizeof(array) / sizeof(array[0]);
        sub = array[0] - array[1];
        for(int i=2;i<size;i++)
        {
         sub = sub - array[i];   
        }
        return sub;
    }
};


namespace lib
{
    template < typename T, typename U, typename ... Ts >
    auto get_max(const T x,const U y,const Ts ... values)
    {
       if constexpr(sizeof ... (Ts) > 0)
        {
            if(x>y)
              {
                return get_max(x, values ... );
              }else
              {
                 return get_max(y, values ... );
              }
        }else
        {
            if(x>y)
            {
                return x;   
            }else
            {
                return y;
            }
        }

    }
    template < typename T, typename U, typename ... Ts >
    auto get_min(const T x,const U y,const Ts ... values)
    {
 static_assert( std::is_arithmetic_v<T> && std::is_arithmetic_v<U>,"must be arithemtic");
        if constexpr(sizeof ... (Ts) > 0)
        {
            if(x<y)
              {
                return get_min(x, values ... );
              }else
              {
                 return get_min(y, values ... );
              }
        }else
        {
            if(x<y)
            {
                return x;   
            }else
            {
                return y;
            }
        }
        return 0;
    }

    template < typename T, typename U, typename ... Ts >
    auto get_sub(T x,U y,Ts ... values)
    {
   static_assert( std::is_arithmetic_v<T> && std::is_arithmetic_v<U>,"must be arithemtic");
        auto z = 0;
     if constexpr(sizeof ... (Ts) > 0)
        {
            if(x>y)
              {
                  z = x-y;
                return get_sub(x, values ... );
              }else
              {
                  z = y-x;
                 return get_sub(y, values ... );
              }
        }else
        {
            return x-y;
        }
    }
    
};

int main() {
    
    int array[] = {1,2,3,4,5};
    std::vector<int> buffer(array,array + 5);
    
    custom cust_data_type(buffer);
    
    std::cout <<"the min number = "<< lib::get_min(5,34,24,323,321,111) << std::endl;
    
    std::cout <<"the max number = " << lib::get_max(55,34,24,323,321,111) <<std::endl;
    
    std::cout <<"the sub number = " << lib::get_sub(55,34,24,323,321,111) << std::endl;
    
    int total_sub = cust_data_type.get_custiomized_sub(buffer);
    std::cout <<"the sub number = " << total_sub;
    
    return 0;
}