using System.Runtime.InteropServices.Swift;

namespace RK2
{
    class Program
    {
        static void Main(string[] args)
        {
            Program prog = new Program();
            
            P p = new P('a');
            H h = new H('b', 3, 5);
            W w = new W('c', 4, 2);
            
            prog.Test(p);
            prog.Test(h);
            prog.Test(w);
        }

        void Test(P obj)
        {
            obj.Print();
        }
    }

    class P
    {
        protected char c;
        public P(char ch)
        {
            c = ch;
        }
        public virtual void Print()
        {
            Console.WriteLine(c);
        }
    }
    class H: P
    {
        private int K;
        private int R;
        public H(char ch, int k, int r): base(ch)
        {
            K = k;
            R = r;
        }
        public override void Print()
        {
            for (int i = 0; i < K; i++)
            {
                Console.Write(" ");

            }
            for (int i = 0; i < R; i++)
            {
                Console.Write(c);
            }
            Console.WriteLine("");
        }
        
    }
    class W: P
    {
        private int K;
        private int R;
        public W(char ch, int k, int r) : base(ch)
        {
            K = k;
            R = r;
        }
        public override void Print()
        {
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < K; j++)
                {
                    Console.Write(c);
                }
                Console.WriteLine("");
            }
        }

    }
}