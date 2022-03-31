using System;
namespace TestSpace
{
    class TestProgram
    {
        public int value = 0;

        //out 参数在函数里一定要赋值
        public static void fun(ref int i, out int j)
        {
            ++i;
            j = 1;
        }

        static void Main(string[] args)
        {
            // {
            //     //1. s2初始化的时候，会拷一份。   s1修改后s2的值不会跟着变
            //     string s1 = new string("s1");
            //     string s2 = s1;
            //     Console.WriteLine(s1);
            //     Console.WriteLine(s2);
            //     s1 = "ss1";
            //     Console.WriteLine(s1);
            //     Console.WriteLine(s2);
            // }
            // {
            //     //2. t 和 tt指向的是同一个对象 
            //     TestProgram t = new TestProgram();
            //     TestProgram tt = t;
            //     Console.WriteLine(t.value);
            //     Console.WriteLine(tt.value);
            //     t.value = 1;
            //     Console.WriteLine(t.value);
            //     Console.WriteLine(tt.value);
            // }
            {
                //3. ref传引用，out是输出参数；out的初值其实没啥作用，因为它在函数里会被重新赋值。
                int i = 1;
                int j = 2;
                fun(ref i, out j);
                Console.WriteLine(i);
                Console.WriteLine(j);
            }


        }
    }
}