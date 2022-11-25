# 章节6参考答案
## 在此代码的结尾，b1和b2各包含多少个元素？
```
StrBlob b1;
{
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
}
```
StrBlob的data成员变量包含一个指向vector<string>类型的shared_ptr，因此StrBlob的赋值不会拷贝vector的内容，而是多个StrBlob对象共享一个vector对象。b2创建时vector中包含3个string，将b2赋值给b1，此时b1和b2指向同一个vector，引用计数为2，b2再添加一个string，最终b1和b2均包含4个string。

## 编写自己的StrBlob类，包含const版本的front和back。
直接查看code

## StrBlob需要const版本的push_back和pop_back嘛？
不需要，因为push_back和pop_back都是修改vector对象的中元素的，常量的StrBlob对象不允许修改共享的vector对象内容。

## 在我们的check函数中，没有检查i是否大于0，为什么可以忽略？
因为check函数是一个私有成员函数，只会被StrBlob的成员函数调用，不会被用户程序调用，所以可以保证传递的参数符合要求。

## 我们？？？

## 编写函数，返回一个动态分配的int的vector。将此vector传递给另一个函数，这个函数读取标准输入，将读入的值保存在vector元素中。再将vector传递给另一个函数，打印读入的值。记得在恰当时刻delete vector。