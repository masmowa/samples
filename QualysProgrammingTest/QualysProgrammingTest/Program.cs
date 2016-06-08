using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/// <summary>
/// create linked list and write function to 
/// Insert a node into a singly linked list (and this should be able to be compiled)
/// </summary>
namespace QualysProgrammingTest
{
    public class Node<T>
    {
        public Node(T data)
        {
            this.data = data;
        }
        public Node<T> next;
        public T data;
    }
    public class MasLinkedList<T>
    {
        public Node<T> Head;

        public Node<T> AddNodeFirst(T data)
        {
            Node<T> node = new Node<T>(data);

            node.next = Head;
            this.Head = node;

            return this.Head;
        }

        public Node<T> Insert(Node<T> where, T data)
        {
            Node<T> node = new Node<T>(data);
            Node<T> after = where;
            if (after == null)
            {
                if (Head == null)
                {
                    this.Head = node;
                }
                else
                {
                    node.next = this.Head;
                    this.Head = node;
                }
            }
            else
            {
                node.next = where.next;
                where.next = node;
            }

            return node; 
        }

        public Node<T> Find(T data)
        {
            Node<T> curr = this.Head;
            while (curr != null)
            {
                if (curr.data.Equals(data))
                {
                    break;
                }
                curr = curr.next;
            }
            return curr;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            Node<T> current = this.Head;
            while (current != null)
            {
                if (sb.Length > 0)
                {
                    sb.Append(", ");
                }
                sb.Append(current.data.ToString());
                current = current.next;
            }
            return sb.ToString();
        }
        public void Dump()
        {
            Console.WriteLine(this.ToString());
        }

    }
    public static class TestLinkedList
    {
        public static void Test()
        {
            int[] testdate = new int[] { 5, 3, 10, 20 };
            int[] toinsert = new int[] { 1, 4 };

            MasLinkedList<int> thelist = new MasLinkedList<int>();
            foreach (int i in testdate)
            {
                thelist.AddNodeFirst(i);
            }
            Console.WriteLine("the initial list: ");
            thelist.Dump();
            string output = string.Format("insert {0} after head", toinsert[0]);
            Console.WriteLine(output);
            Node<int> inserted = thelist.Insert(thelist.Head, toinsert[0]);
            Console.WriteLine("After Insert After Head");
            thelist.Dump();
            output = string.Format("insert {0} after last insert", toinsert[1]);
            Console.WriteLine(output);
            Node<int> second = thelist.Insert(inserted, toinsert[1]);
            Console.WriteLine("After insert after last insert");
            thelist.Dump();
            Console.Write("Press Enter to continue: ");
            string ling = Console.ReadLine();
        }
    }

    /// <summary>
    /// Convert an alphanumeric string to a numeric string. 
    /// (in your answer list any assumptions that you are making, this code should be able to be called and reused)
    /// </summary>
    /// <assumption>
    /// I am going to assume I want a decimal value returned
    /// </assumption>
    public static class ConvertAlNumStr
    {
        public static string FromHex(string input)
        {
            string result = null;
            string current = null;
            int value = 0;
            const int RADIX = 16;
            if (input.StartsWith("0x"))
            {
                current = input.Substring(2);
                Console.WriteLine(string.Format("the string: {0}", current));
                foreach (char c in current)
                {
                    if (Char.IsDigit(c))
                    {
                        value = value * RADIX + (int)(c - '0');
                    }
                    else
                    {
                        if ("abcdef".Contains(Char.ToLower(c)))
                        {
                            value = value * RADIX + ((int)(char.ToLower(c) - 'a') + 10);
                        }
                    }
                }
                result = value.ToString();
            }
            return result;

        }
        public static string Convert(string input)
        {
            string result = null;
            if (input.StartsWith("0x"))
            {
                result = ConvertAlNumStr.FromHex(input);
            }
            else if (input.Contains("."))
            {
                try
                {
                    double val = Double.Parse(input);
                }
                catch (FormatException)
                {
                    Console.WriteLine("{0} bad formt ", input);
                }
                catch (OverflowException)
                {
                    Console.WriteLine("{0} overflow int32", input);
                }
            }
            else
            {
                // use int32
                try
                {
                    int val = Int32.Parse(input);
                    result = val.ToString();
                }
                catch (FormatException)
                {
                    Console.WriteLine("{0} bad formt ", input);
                }
                catch (OverflowException)
                {
                    Console.WriteLine("{0} overflow int32", input);
                }
            }
            return result;
        }
    }
    public static class TestAlNumParse
    {
        public static void TestHex()
        {
            string[] values = { "2345", "0x0001", "0xa", "0x1001", "0xf1e2", "99.99", "0xyz" };
            foreach (string val in values)
            {
                string res = ConvertAlNumStr.Convert(val);
                Console.WriteLine("input: {0} conversion {1}", val, res);
            }
            Console.Write("Press Enter to continue: ");
            string ling = Console.ReadLine();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            TestLinkedList.Test();
            TestAlNumParse.TestHex();
        }
    }
}
