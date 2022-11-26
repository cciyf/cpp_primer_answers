# 章节13参考答案
## 13.1 拷贝构造函数是什么，什么时候使用它？

如果构造函数的第一个参数是自身类型的引用，且其他所有参数都有默认值，则此构造函
数是拷贝构造函数。拷贝构造函数再以下几种情况会被使用：
1. 拷贝初始化（用=定义变量）
2. 将一个对象作为实参传递给非引用类型的形参。
3. 一个返回类型为非引用类型的函数返回一个对象。
4. 用花括号列表初始化一个数组中的元素或一个聚合类中的成员。
5. 初始化标准库容器或调用其insert/push操作时，容器会对其元素进行拷贝初始化。

## 13.2 解释为什么下面的声明是非法的？
```
Sales_data::Sales_data(Sales_data rhs);
```
这一声明是非法的。这样会造成死循环，因为我们需要调用拷贝构造函数，但其自身的参数类型也是非引用类型类型，为了调用它，又需要拷贝其实参，从而又需要调用拷贝构造函数，造成了死循环。

## 13.3 当我们拷贝一个StrBlob时，会发生什么？拷贝一个StrBlobPtr呢？

## 13.4 假定Point是一个类类型，它有一个public的拷贝构造函数，指出下面程序片段中哪些地方使用了拷贝构造函数：
```
Point global;
Point foo_bar(Point arg)
{
    Point local = arg, *heap = new Point(global);
    *heap = local;
    Point pa[ 4 ] = { local, *heap };
    return *heap;
}
```
如下几个地方使用了拷贝构造函数：
1. `Point local = arg`使用了拷贝构造函数，将arg拷贝给local。
2. `*heap = local`使用了拷贝构造函数。
3. `Point pa[ 4 ] = { local, *heap }`使用了拷贝构造函数。
4. `return *heap`使用了拷贝构造函数。

## 13.5 给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。你的构造函数应该动态分配一个新的string，并将对象拷贝到ps指向的位置，而不是拷贝ps本身。
```
class HasPtr{
public:
    HasPtr(const std::string &s = std::string()) : 
        ps(new std::string(s)), i(0) {}
private:
    std::string *ps;
    int i;
};
```

```
    HasPtr(const HasPtr &hp) {
        ps = new string(*hp.ps);
        i = hp.i;
    }
```

