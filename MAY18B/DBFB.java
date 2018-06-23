import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
 
/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author abhiy13
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }
 
    static class TaskD {
        static final long MOD = 1000000007;
        static long val;
 
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            long m = in.nextLong();
            long[] a = new long[(int) n];
            long[] b = new long[(int) n];
 
            for (int i = 0; i < n; i++) {
                a[i] = in.nextLong();
            }
            for (int i = 0; i < n; i++) {
                b[i] = in.nextLong();
            }
            if (m <= 100) {
                out.println(solve1(n, m, a, b));
            } else {
                val = 0;
                long y = 0, x = 0;
                for (int i = 0; i < n; i++) {
                    y += (fib(m - 1, 0, b[i])) % MOD;
                    y %= MOD;
                }
                for (int i = 0; i < n; i++) {
                    x += (((((n % MOD) * (val % MOD)) % MOD) * (a[i]) % MOD) % MOD + y % MOD) % MOD;
                    x %= MOD;
                }
                out.println(x);
            }
        }
 
        static long fib(long n, long a, long b) {
            long[][] F = new long[][]{{1, 1}, {1, 0}};
            if (n < 0) return 0;
            val = 1;
            if (n == 0) return a % MOD;
            if (n == 1) return b % MOD;
            pow(F, n - 1);
            val = F[0][1] % MOD;
            return (b * F[0][0]) % MOD;
        }
 
        private long solve1(long n, long m, long a[], long b[]) {
            long res = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    res += fib2(m - 1, a[i], b[i]);
                    res %= MOD;
                }
            }
            return res;
        }
 
        static long fib2(long n, long a, long b) {
            long[][] F = new long[][]{{1, 1}, {1, 0}};
            if (n < 0) return 0;
            if (n == 0) return a % MOD;
            if (n == 1) return b % MOD;
            if (n == 2) return (a + b) % MOD;
            pow(F, n - 1);
            return ((b * F[0][0]) % MOD + (a * F[0][1]) % MOD) % MOD;
        }
 
        static void multiply(long F[][], long M[][]) {
            long x = ((F[0][0] * M[0][0]) % MOD + (F[0][1] * M[1][0]) % MOD) % MOD;
            long y = ((F[0][0] * M[0][1]) % MOD + (F[0][1] * M[1][1]) % MOD) % MOD;
            long z = ((F[1][0] * M[0][0]) % MOD + (F[1][1] * M[1][0]) % MOD) % MOD;
            long w = ((F[1][0] * M[0][1]) % MOD + (F[1][1] * M[1][1]) % MOD) % MOD;
            F[0][0] = x;
            F[0][1] = y;
            F[1][0] = z;
            F[1][1] = w;
        }
 
        static void pow(long F[][], long n) {
            if (n == 0 || n == 1)
                return;
            long M[][] = new long[][]{{1, 1}, {1, 0}};
            pow(F, n / 2);
            multiply(F, F);
            if (n % 2 != 0)
                multiply(F, M);
        }
 
    }
 
    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;
 
        public InputReader(InputStream stream) {
            this.stream = stream;
        }
 
        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }
 
        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public String nextString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }
 
        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }
 
        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public String next() {
            return nextString();
        }
 
        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
 
        }
 
    }
}
 
 
