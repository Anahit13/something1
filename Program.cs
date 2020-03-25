using System;

namespace ConsoleApp2
{
    class Pro
    {
        private string title = "asdfgh";
        private string description = "klopmj";

        public string Title
        {
            get
            { return title; }

        }

        public string Description
        {
            get
            { return description; }
        }
    };

    class Program
    {
        static void Main(string[] args)
        {
            Pro obj = new Pro();

            //Console.WriteLine("Title is:" + obj.Title);
            //Console.WriteLine("Description is:" + obj.Description);
            
            Console.WriteLine("Write something you want to find");
            Console.Write("something=");
            string something = Console.ReadLine();

            if (something.CompareTo(obj.Description) == 0)
                Console.WriteLine($"Both: something and Description strings have same value.") ;
            else if(something.CompareTo(obj.Title) == 0)
                    Console.WriteLine($"Both:something and Title strings have same value.");
            else if (something.CompareTo(obj.Title) != 0)
                Console.WriteLine($"Maybe you're looking for " + obj.Title);
            else if (something.CompareTo(obj.Description) != 0)
                Console.WriteLine($"Maybe you're looking for " + obj.Description);

        }
    }
}
