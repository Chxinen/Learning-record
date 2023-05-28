# Leetcode

## 1 两数和

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> a;
        for(int i=0;i<nums.size();i++){
                auto iter=a.find(target-nums[i]);
                if(iter!=a.end()){
                    return {iter->second,i};//符合条件的pair的下标
                }
                a.insert(pair<int,int>(nums[i],i));
        }
        return {};
    }
};
```

### map的使用

unordered_map不知其原理（还有另外两种map）

a.find()是比对pair的第一个值key，因为是个迭代器，所以用auto。

没找到返回的是a.end()，找到返回的应该是pair。

### return + { }

c++11特性，总的来说就是要什么类型返回什么类型

原文解释

If the braced-init-list is empty and T is a class type with a default constructor, value-initialization is performed.

Otherwise, if T is an aggregate type, aggregate initialization is performed.

Otherwise, if T is a specialization of std::initializer_list, the T object is direct-initialized or copy-initialized, depending on context, from the braced-init-list.

Otherwise, the constructors of T are considered, in two phases:
 - All constructors that take std::initializer_list as the only
argument, or as the first argument if the remaining arguments have
default values, are examined, and matched by overload resolution
against a single argument of type std::initializer_list
 - If the previous stage does not produce a match, all constructors of T
participate in overload resolution against the set of arguments that
consists of the elements of the braced-init-list, with the restriction
that only non-narrowing conversions are allowed. If this stage
produces an explicit constructor as the best match for a
copy-list-initialization, compilation fails (note, in simple
copy-initialization, explicit constructors are not considered at all).

Otherwise (if T is not a class type), if the braced-init-list has only one element and either T isn’t a reference type or is a reference type that is compatible with the type of the element, T is direct-initialized (in direct-list-initialization) or copy-initialized (in copy-list-initialization), except that narrowing conversions are not allowed.

Otherwise, if T is a reference type that isn’t compatible with the type of the element. (this fails if the reference is a non-const value reference).

Otherwise, if the braced-init-list has no elements, T is value-initialized.

## 9 回文数

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||x%10==0&&x!=0) return false;
        else {
            long sum=0;
            int temp=x;
            while(x){
                sum=sum*10+x%10;//不需要用pow，也不需要用循环来乘10
                x/=10;
            }
            return (sum==temp?true:false);
        }
    }
};
```

尽可能少用循环，用三次循环就会超时，更别提嵌套

可以把绝对不为回文的数先提出来，也可以节约时间