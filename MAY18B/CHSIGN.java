import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
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
        TaskF solver = new TaskF();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }
 
    static class TaskF {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            long[] ar = new long[(int) n];
            for (int i = 0; i < n; i++) {
                ar[i] = in.nextLong();
            }
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    if (ar[i] < ar[i + 1]) ar[0] *= -1;
                    continue;
                } else if (i == n - 1) {
                    if (ar[i] < ar[i - 1]) ar[i] *= -1;
                    continue;
                }
                if (ar[i] < ar[i - 1] && ar[i] < ar[i + 1]) ar[i] *= -1;
            }
            ArrayList<Integer> p = new ArrayList<Integer>();
            ArrayList<Long> q = new ArrayList<Long>();
            int z = 0;
            while (z < (int) n) {
                if (ar[z] < 0) {
                    q.add(ar[z]);
                    p.add(z);
                    z++;
                } else {
                    long sum = 0;
                    while (z < (int) n) {
                        if (ar[z] <= 0) break;
                        sum += ar[z];
                        z++;
                    }
                    q.add(sum);
                    p.add(-1);
                }
            }
            int size = q.size();
            long[][] dp = new long[size][2];
            long[] A = new long[size];
            long[] B = new long[size];
            Arrays.fill(A, 1);
            Arrays.fill(B, 1);
            for (int i = 0; i < size; i++) {
                if (i == 0) {
                    dp[0][0] = (q.get(i) * ((q.get(i) > 0) ? 1 : -1));
                    dp[0][1] = q.get(i);
                    continue;
                } else if (i == 1) {
                    if (q.get(i) > 0) {
                        dp[1][0] = dp[0][0] + q.get(i);
                        dp[1][1] = dp[0][1] + q.get(i);
                    } else {
                        dp[1][0] = Math.min(dp[0][0], dp[0][1]) + q.get(i) * -1;
                        dp[1][1] = Math.min(dp[0][0], dp[0][1]) + q.get(i);
                    }
                    continue;
                }
                if (q.get(i) > 0) {
                    dp[i][0] = dp[i - 1][0] + q.get(i);
                    dp[i][1] = dp[i - 1][1] + q.get(i);
                } else {
                    dp[i][0] = Math.min(dp[i - 1][0], dp[i - 1][1]) + q.get(i) * -1;
                    if (q.get(i) + q.get(i - 1) + q.get(i - 2) > 0) {
                        dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][1]) + q.get(i);
                    } else {
                        B[i] = 0;
                        dp[i][1] = dp[i - 1][0] + q.get(i);
                    }
                }
            }
            int decider = 0;
            for (int i = size - 1; i > 0; i--) {
                if (i == size - 1) {
                    decider = (dp[i][1] < dp[i][0]) ? 1 : 0;
                }
                if (q.get(i) < 0) {
                    if (decider == 0) {
                        A[i] = -1;
                        if (dp[i - 1][1] < dp[i - 1][0]) decider = 1;
                        else decider = 0;
                    } else {
                        if (B[i] == 0) {
                            decider = 0;
                        } else {
                            if (dp[i - 1][1] < dp[i - 1][0]) decider = 1;
                            else decider = 0;
                        }
                    }
                }
            }
            if (q.get(0) < 0) {
                if (decider == 0) A[0] = -1;
            }
            for (int i = 0; i < size; i++) {
                if (A[i] == -1) {
                    ar[p.get(i)] *= -1;
                }
            }
 
            for (int i = 0; i < n; i++) {
                out.print(ar[i] + " ");
            }
            out.print("\n");
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
 
 
