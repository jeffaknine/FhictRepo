using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IteratorDesignPatter
{
    class Program
    {
        static void Main(string[] args)
        {
            HomeTheater home = new HomeTheater();
            Console.WriteLine(" This is a TV remote control"+
                                "\n Type the 'n' key followed by enter to get the next channel and 'p' for the previous one"+
                                "\n Type the 's' key to switch to the radio and 's' to switch back to tv");

            while(true)
            {
                string key = Console.ReadLine();
                if(key == "s")
                {
                    home.Switch();
                    Console.WriteLine("switched to"+home.Get());
                }
                else
                {
                    string s = home.GetNext(key);
                    Console.WriteLine("Current Channel is : " + s); 
                }           
            }
            
        }
    }
}
