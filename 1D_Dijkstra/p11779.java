package boj.dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.StringTokenizer;

public class p11779 {

	public static void main(String[] args) {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			int n, m;
			n = Integer.parseInt(br.readLine());
			m = Integer.parseInt(br.readLine());
			
			List<int[]>[] edges = new List[n+1];
			for (int v = 1; v <= n; v++) {
				edges[v] = new ArrayList<int[]>();
			}
			
			StringTokenizer st = null;
			while(m-- > 0) {
				st = new StringTokenizer(br.readLine());
				int u, v, w;
				u = Integer.parseInt(st.nextToken());
				v = Integer.parseInt(st.nextToken());
				w = Integer.parseInt(st.nextToken());
				edges[u].add(new int[] {v, w});
			}
			int start, end;
			st = new StringTokenizer(br.readLine());
			start = Integer.parseInt(st.nextToken());
			end = Integer.parseInt(st.nextToken());
			
			int[] d = new int[n+1];
			for (int v = 1; v <= n; v++) {
				d[v] = Integer.MAX_VALUE;
			}
			
			int[] prior = new int[n+1];
			
			PriorityQueue<int[]> PQ = new PriorityQueue<int[]>(
					(a, b) -> Integer.compare(a[1], b[1]));
			
			d[start] = 0;
			PQ.add(new int[] {start, 0});
			
			while(!PQ.isEmpty()) {
				int[] cur = PQ.poll();
				if (d[cur[0]] < cur[1])	continue;
				if (cur[0] == end)	break;
				for (int[] adj : edges[cur[0]]) {
					if (d[adj[0]] > d[cur[0]] + adj[1]) {
						d[adj[0]] = d[cur[0]] + adj[1];
						prior[adj[0]] = cur[0];
						PQ.add(new int[] {adj[0], d[adj[0]]});
					}
				}
			}
			
			System.out.println(d[end]);
			Deque<Integer> path = new ArrayDeque<Integer>();
			path.add(end);
			while(path.peekLast() != start) {
				path.add(prior[path.peekLast()]);
			}
			System.out.println(path.size());
			while(!path.isEmpty()) {
				System.out.print(path.pollLast() + " ");
			}
			
		} catch (IOException e) {
			
		}

	}

}
