// using System;

// namespace SwitchTestNamespace
// {
//     struct Point
//     {
//         public double x;
//         public double y;
//     }

//     class Poly
//     {
//         public Point centerPoint;
//         public Poly()
//         {
//             centerPoint.x = 0.0;
//             centerPoint.y = 0.0;
//         }
//     }

//     class Circle : Poly
//     {
//         public double nRadius;
//         public Circle() : base()
//         {
//             nRadius = 10.0;
//         }
//     }

//     class Square : Poly
//     {
//         public double nBorder;
//         public Square() : base()
//         {
//             nBorder = 5.0;
//         }
//     }

//     class Triangle : Poly
//     {
//         public double nBorder;
//         public Triangle() : base()
//         {
//             nBorder = 3.0;
//         }
//     }

//     class MainClass
//     {
//         public static void Main(string[] args)
//         {
//             Circle c = new Circle();
//             Square s = new Square();
//             Triangle t = new Triangle();
//             object o = t;
//             switch(o)
//             {
//             case Circle myCircle :
//                 Console.WriteLine($"This is a circle, radius is {myCircle.nRadius}");
//                 break;
//             case Square mySquare when mySquare.nBorder > 100:
//                 Console.WriteLine($"This is a Square, radius is {mySquare.nBorder}");
//                 break;
//             case Triangle :
//                 Console.WriteLine($"This is a Triangle");
//                 break;
//             default:
//                 Console.WriteLine($"Default");
//                 break;
//             }
//         }
//     }
// }