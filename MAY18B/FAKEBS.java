import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
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
        TaskE solver = new TaskE();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }
 
    static class TaskE {
        static int binary_search(long ar[], long n, long x) {
            int l = 0, h = (int) n - 1;
            while (l <= h) {
                int mid = (l + h) >> 1;
                if (ar[mid] == x) {
                    return mid;
                }
                if (ar[mid] > x) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return 0;
        }
 
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong(), q = in.nextLong();
            long[] ar = new long[(int) n];
            long[] br = new long[(int) n];
            HashMap<Long, Integer> idx = new HashMap<Long, Integer>();
            for (int i = 0; i < n; i++) {
                ar[i] = in.nextLong();
                br[i] = ar[i];
                idx.put(ar[i], i);
            }
            Arrays.sort(br);
            while (q-- > 0) {
                long px = in.nextLong();
                int ip = binary_search(br, n, px);
                //if(ip == -1) throw new RuntimeException();
                //out.println(ip+" "+px+" "+idx.get(px));
                out.println(solver(ar, n, px, idx.get(px), ip));
            }
        }
 
        static long solver(long[] ar, long n, long px, int index, int ip) {
            int l = 0, h = (int) n - 1, A = 0, B = 0, a = 0, b = 0;
            while (l <= h) {
                int mid = (l + h) >> 1;
                if (mid == index) break;
                if (mid < index) {
                    l = mid + 1;
                    b++;
                    if (ar[mid] > px) {
                        B++;
                    }
                } else {
                    h = mid - 1;
                    a++;
                    if (ar[mid] < px) {
                        A++;
                    }
                }
            }
            if (ip < b || a > (int) n - 1 - ip) return -1;
            else return Math.max(A, B);
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
 
 
