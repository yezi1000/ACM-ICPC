import java.awt.Point;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

import javax.xml.bind.ValidationEvent;

import org.omg.PortableServer.ID_ASSIGNMENT_POLICY_ID;

public class Solutions {

	static Scanner in = new Scanner();
	static PrintWriter out = new PrintWriter(System.out);
	static ArrayList<Integer> all;
	static int max_len = 9;

	public static void main(String[] args) throws IOException {
		int k = in.nextInt();
		all = new ArrayList<>();
		Gen(10, 0, 0);
		// out.println(all);
		out.println(all.get(k - 1));
		out.flush();
		out.close();
	}

	static void Gen(int sum, int number, int len) {
		if (len == max_len) {
			if (sum == 0) {
				all.add(number);
			}
		} else {
			for (int i = 0; i <= Math.min(sum, 9); i++) {
				Gen(sum - i, number * 10 + i, len + 1);
			}
		}
	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public Scanner(FileReader fileReader) throws FileNotFoundException {
			br = new BufferedReader(fileReader);
		}

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public double nextDouble() throws IOException {
			String x = next();
			StringBuilder sb = new StringBuilder("0");
			double res = 0, f = 1;
			boolean dec = false, neg = false;
			int start = 0;
			if (x.charAt(0) == '-') {
				neg = true;
				start++;
			}
			for (int i = start; i < x.length(); i++)
				if (x.charAt(i) == '.') {
					res = Long.parseLong(sb.toString());
					sb = new StringBuilder("0");
					dec = true;
				} else {
					sb.append(x.charAt(i));
					if (dec)
						f *= 10;
				}
			res += Long.parseLong(sb.toString()) / f;
			return res * (neg ? -1 : 1);
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

	}

}