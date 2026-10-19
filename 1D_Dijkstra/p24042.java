
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N, M;
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			
			List<int[]>[] edges = new List[N+1];
			for (int i = 1; i <= N; i++) {
				edges[i] = new ArrayList<int[]>();
			}
			
			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int A, B;
				A = Integer.parseInt(st.nextToken());
				B = Integer.parseInt(st.nextToken());
				edges[A].add(new int[] {B, i+1});
				edges[B].add(new int[] {A, i+1});
			}
			
			int[] d = new int[N+1];
			for (int i = 1; i <= N; i++) {
				d[i] = Integer.MAX_VALUE;
			}
			
			PriorityQueue<int[]> PQ = new PriorityQueue<int[]>(
					(a,b) -> Integer.compare(a[1], b[1]));
			
			PQ.add(new int[] {1, 0});
			
			int t = 0;
			while(!PQ.isEmpty()) {
				int[] cur = PQ.poll();
//				System.out.println("cur is " + cur[0] + "," + cur[1] + " at " + t);
				int time = cur[1];
				int region = cur[0];
				if (d[region] != Integer.MAX_VALUE)	continue;
				if (time < t) {
					while (time < t)	time += M;
					PQ.add(new int[] {region, time});
					continue;
				}
				d[region] = time;
//				System.out.println(region + " arrived at " + t);
//				System.out.println(region + "," + time + " arrived at " + t);
				t = time + 1;
				if (region == N) {
					System.out.println(d[region]);
					return;
				}
				for (int[] adj : edges[region]) {
					int next_r = adj[0];
					int cost = adj[1];
					if (d[next_r] != Integer.MAX_VALUE)	continue;
					while (cost < t)	cost += M;
					PQ.add(new int[] {next_r, cost});
				}
						
			}
			
		} catch (IOException e) {
			
		}

	}

}
