// using System;

// namespace StructAndClass
// {
//     struct TestStruct
//     {
//         public int t1 { get; set; }
//         public TestStruct() 
//         {
//             t1 = 1;
//         }
//     } 

//     class TestClass
//     {
//         public int t1 { get; set; }
//         public TestClass() 
//         {
//             t1 = 1;
//         }
//         public virtual void testFun()
//         {
//             Console.WriteLine("This is Base Class!");
//         }
//     }

//     class DerivedClass : TestClass
//     {
//         public override void testFun()
//         {
//             Console.WriteLine("This is Derived Class!");
//         }
//     }

//     class DerivedClass1 : DerivedClass
//     {
//         public override void testFun()
//         {
//             Console.WriteLine("This is Derived Class1!");
//         }
//     }

//     class Test
//     {
//         public static void Main(string[] args)
//         {
//             {
//                 //1. struct是值类型的，class是引用类型的
//                 TestStruct s1 = new TestStruct();
//                 TestStruct s2 = s1;
//                 Console.WriteLine("s1: {0}, s2: {1}", s1.t1, s2.t1);
//                 s1.t1 = 2;
//                 Console.WriteLine("s1: {0}, s2: {1}", s1.t1, s2.t1);

//                 TestClass c1 = new TestClass();
//                 TestClass c2 = c1;
//                 Console.WriteLine("c1: {0}, c2: {1}", c1.t1, c2.t1);
//                 c1.t1 = 2;
//                 Console.WriteLine("c1: {0}, c2: {1}", c1.t1, c2.t1);

//                 Console.WriteLine("s1 hashCode: {0}; s2 hashCode: {1}", s1.GetHashCode(), s2.GetHashCode());
//                 Console.WriteLine("c1 hashCode: {0}; c2 hashCode: {1}", c1.GetHashCode(), c2.GetHashCode());
//             }

//             {
//                 //2. C#和C++的虚函数有点不太一样，C#的子类函数需要用override声明，否则就是覆盖，而不是重载；基类的虚函数需要用virtual声明
//                 TestClass c1 = new TestClass();
//                 TestClass c2 = new DerivedClass();
//                 TestClass c3 = new DerivedClass1();
//                 c1.testFun();
//                 c2.testFun();
//                 c3.testFun();
//             }

//         }
//     }

// }