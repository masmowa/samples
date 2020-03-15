using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Net;
using System.IO;

namespace SortListOfIPStrings
{
    public class ArrayOfIPAddressStrings 
    {
        protected string[] ipStrings;
        public string[] IpStrings
        {
            get { return this.ipStrings; }
            set { this.ipStrings = value; }
        }

        protected string[] ipStrSorted;
        public string[] IpStrSorted
        {
            get { return this.ipStrSorted; }
            set { this.ipStrSorted = value; }
        }

        protected int[] ipAsInt;
        public int[] IpAsInt
        {
            get { return this.ipAsInt; }
            set { this.ipAsInt = value; }
        }

        protected List<IPAddress> ipAddrs;

        public List<int> ipAsInts;
        public List<string> ipAddrStrs;


        public void ReadFromFile(string filepath)
        {
            //using (FileStream fs = File.Open(filepath, FileMode.Open, FileAccess.Read, FileShare.Read))
            //{
            try
            {
                ipStrings = System.IO.File.ReadAllLines(filepath);
            }
            catch (Exception e) 
            {
                // Let the user know what went wrong.
                Console.WriteLine("The file could not be read:");
                Console.WriteLine(e.Message);
            }
            //}
        }

        public static int IPStrToInt32 (string input)
        {
            Console.WriteLine("Input: [{0}], [{1}]", input, input.Trim());
            //return (long)(uint)IPAddress.NetworkToHostOrder((int)IPAddress.Parse(input).Address);
            Byte[] baval = { 0, 0, 0, 0 };
            baval = IPAddress.Parse(input.Trim()).GetAddressBytes();
            foreach (byte b in baval)
            {
                Console.Write(b);
                Console.Write(" ");
            }
            Console.WriteLine("");
            Array.Reverse(baval);
            foreach (byte b in baval)
            {
                Console.Write(b);
                Console.Write(" ");
            }
            Console.WriteLine("");

            int ival = new int();
            ival = System.BitConverter.ToInt32(baval, 0);
            //IPAddress ipbytes = new IPAddress(input).GetAddressBytes();
            Console.WriteLine("IP as int: {0}", ival);
            return ival;
        }

        public static string IPStrFromInt32 (int input)
        {
            return new IPAddress(BitConverter.GetBytes(input).Reverse().ToArray<byte>()).ToString();
        }


        public void SortAsStr()
        {
            ipStrSorted = ipStrings;
            Array.Sort(ipStrSorted);
        }

        public void Dump(string [] input, string prompt)
        {
            Console.WriteLine(prompt);
            foreach (string line in input)
            {
                Console.WriteLine("{0}", line);
            }
            Console.WriteLine("");
        }
        static public void Dump( List<string> input, string prompt)
        {
            Console.WriteLine(prompt);
            foreach (string line in input)
            {
                Console.WriteLine(line);
            }
            Console.WriteLine("");
        }
        public void DumpUnsorted()
        {
            this.Dump(this.ipStrings, "Unsorted IP strings: ");
        }

        public void DumpSorted()
        {
            this.Dump(ipStrSorted, "Sorted string IP strings :");
        }
        public void SortAsInt()
        {
            ipAddrs = new List<IPAddress>();
            ipAsInts = new List<int>();
            if (ipAddrs != null)
            {
                foreach (string line in this.ipStrings)
                {
                    int val = ArrayOfIPAddressStrings.IPStrToInt32(line);
                    try
                    {
                        ipAsInts.Add(val);
                    }
                    catch (Exception e)
                    {
                        // Let the user know what went wrong.
                        Console.WriteLine("problem while adding value:");
                        Console.WriteLine(e.Message);
                    }
                }
            }
            Array.Sort<int>(ipAsInts.ToArray());
            ConvertToArrayOfStrings();
        }

        protected void ConvertToArrayOfStrings()
        {
            ipAddrStrs = new List<string>();
            foreach (int ipint in ipAsInts)
            {
                string val = ArrayOfIPAddressStrings.IPStrFromInt32(ipint);
                ipAddrStrs.Add(val);
            }
            Dump(ipAddrStrs, "Sorted as Array of INTs: ");
        }
    }
    class Program
    {

        static void Main(string[] args)
        {
            ArrayOfIPAddressStrings ips = new ArrayOfIPAddressStrings();
            string path_to_test_file = @"C:\Users\Mark\Documents\GitHub\samples\SortListOfIPStrings\SortListOfIPStrings\ListOfIP.txt";
            ips.ReadFromFile(path_to_test_file);
            ips.DumpUnsorted();

            ips.SortAsStr();
            ips.DumpSorted();

            ips.SortAsInt();
           

            Console.Write("Press Enter to continue: ");
            string ling = Console.ReadLine();

        }
    }
}
