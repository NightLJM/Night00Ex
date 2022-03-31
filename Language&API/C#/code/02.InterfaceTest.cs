// using System;

// namespace InterfaceTest
// {
//     interface TestInterface
//     {
//         int a { get; set; }
//         int b { get; set; }
//         void fun();
//     }

//     class TestClass : TestInterface
//     {
//         public int a { get; set; }
//         public int b { get; set; }

//         public virtual void fun()
//         {
//             Console.WriteLine("This is Class fun");
//         }
//     }

//     class TestClass1 : TestClass
//     {
//         public override void fun()
//         {
//             Console.WriteLine("This is Class1 fun");
//         }
//     }

//     class TestClass2 : TestInterface
//     {
//         public int a { get; set; }
//         public int b { get; set; }
//         public virtual void fun()
//         {
//             Console.WriteLine("This is Class2 fun");
//         }
//     }

//     class TestClass3 : TestClass
//     {
//         public virtual void fun()       //其实是覆盖
//         {
//             Console.WriteLine("This is Class3 fun");
//         }
//     }

//     class MainClass
//     {
//         public static void Main(string[] args)
//         {
//             TestInterface c1 = new TestClass();
//             TestInterface c2 = new TestClass1();
//             TestInterface c3 = new TestClass2();
//             TestInterface c4 = new TestClass3();
//             c1.fun();
//             c2.fun();
//             c3.fun();
//             c4.fun();
//         }
//     }
// }