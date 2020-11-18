import java.io.ObjectInputStream.GetField;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;

public class Graphsvs {

	public static void main(String[] args) {
		Constructor();
		// display();
		// removeVertex(0);
		// display();
		boolean[] vis = new boolean[7];
		// haspaths(0, 6, vis, "0"+"");
		// allpaths(0, 6, vis,"0"+"");
//		AllConditions(0, 6, 0, vis,"0"+"");
//		System.out.println(swp);
//		System.out.println(gwp);
		System.out.println(gcc());
//		removeEdge(3, 4);
//		System.out.println(gcc());

		// BFS(0);
		// bfslevel(0);
//		bfs2(0);
		HamiltonianPath(0, 0, vis, 0, "0" + "");
		// bipartite();
		// Topological();
		// KhansAlgo();
		// Kosaraju();
		// Djikstra();
	}

	public static class Edge {
		int w = 0;
		int v = 0;

		Edge(int v, int w) {
			this.v = v;
			this.w = w;
		}
	}

	public static ArrayList<ArrayList<Edge>> graph = new ArrayList<>();

	public static void Constructor() {
		int n = 7;
		for (int i = 0; i < n; i++) {
			graph.add(new ArrayList<>());
		}

		AddEdge(0, 1, 10);
		AddEdge(0, 3, 10);
		AddEdge(1, 2, 10);
		AddEdge(2, 3, 40);
		AddEdge(3, 4, 2);
		AddEdge(4, 5, 2);
		AddEdge(4, 6, 3);
		AddEdge(5, 6, 8);
		AddEdge(2, 5, 8); // 1-->2 edges for hamiltonian path
		AddEdge(0, 6, 2); // 2.
		// *********************************graph for topological sort(directional
		// graph)***********
//		AddEdge(0, 4, 1);
//		AddEdge(0, 1, 1);
//		AddEdge(1, 2, 1);
//		AddEdge(2, 3, 1);
//		AddEdge(5, 4, 1);
//		AddEdge(5, 6, 1);
//		AddEdge(6, 7, 1);
//		AddEdge(7, 3, 1);
//		display();
		System.out.println();

	}

	public static void constructGraph2() {

		AddEdge(4, 0, 1);
		AddEdge(1, 0, 1);
		AddEdge(2, 1, 1);
		AddEdge(3, 2, 1);
		AddEdge(4, 5, 1);
		AddEdge(6, 5, 1);
		AddEdge(7, 6, 1);
		AddEdge(3, 7, 1);

		// *************************8
		removeEdge(0, 4, 1);
		removeEdge(0, 1, 1);
		removeEdge(1, 2, 1);
		removeEdge(2, 3, 1);
		removeEdge(5, 4, 1);
		removeEdge(5, 6, 1);
		removeEdge(6, 7, 1);
		removeEdge(7, 3, 1);

	}

	public static void AddEdge(int u, int v, int w) {
		if (u < 0 || v < 0 || u >= graph.size() || v >= graph.size()) {
			return;
		}
		graph.get(u).add(new Edge(v, w));
		graph.get(v).add(new Edge(u, w));
	}

	public static void display() {

		for (int i = 0; i < graph.size(); i++) {

			System.out.print(i + "->" + " ");
			for (Edge e : graph.get(i)) {
				System.out.print("(" + e.v + "," + e.w + ")");
			}
			System.out.println();
		}
	}

	public static void removeEdge(int u, int v, int w) {
		// graph.get(u);
		int i = 0;
		while (graph.get(u).size() != 0) {
			Edge e = graph.get(u).get(i);
			if (e.v == v) {
				break;
			}
			i++;
		}
		int j = 0;
		while (graph.get(v).size() != 0) {
			Edge e = graph.get(v).get(j);
			if (e.v == u) {
				break;
			}
			j++;
		}
		graph.get(u).remove(i);
		// graph.get(v).remove(j);
	}

	public static void removeVertex(int u) {
//		for(Edge e :graph.get(u)) {  Why this is not working?????
//			removeEdge(u, e.v);
//		}

//		int n=graph.get(u).size()-1;   this is also not working ???why ????
//		for(int i=0;i<n;i++) {
//			Edge e=graph.get(u).get(i);
//			removeEdge(u, e.v);
//		}
		ArrayList<Edge> list = graph.get(u);
		int i = 0;
		while (list.size() != 0) {
			Edge e = list.get(list.size() - 1);
			removeEdge(u, e.v, 0);
		}

	}
	// *******************************************HAS PATHS(boolean ) or void

	public static void haspaths(int src, int dest, boolean[] vis, String psf) {

		for (Edge e : graph.get(src)) {
			if (src == dest) {
				System.out.println(psf);
			}

			vis[src] = true;
			if (!vis[e.v]) {
				haspaths(e.v, dest, vis, psf + e.v + " ");
			}
		}

	}

//*************************************** ALL PATHS
	public static void allpaths(int src, int dest, boolean[] vis, String psf) {
		if (src == dest) {
			System.out.println(psf);
			return;
		}
		vis[src] = true;
		for (Edge e : graph.get(src)) {
			if (!vis[e.v]) {
				allpaths(e.v, dest, vis, psf + e.v + "");
			}
		}
		vis[src] = false;
	}

	// ************************************ALL Conditions(greates path,smallest
	// path)
	static int swsf = Integer.MAX_VALUE;
	static int gwsf = Integer.MIN_VALUE;
	static String swp = "";
	static String gwp = "";

	public static void AllConditions(int src, int dest, int wt, boolean[] vis, String psf) {
		if (src == dest) {
			if (wt < swsf) {
				swsf = wt;
				swp = psf + "@" + swsf;
			}
			if (wt > gwsf) {
				gwsf = wt;
				gwp = psf + "@" + gwsf;
			}
			// System.out.println(psf);
		}
		vis[src] = true;
		for (Edge e : graph.get(src)) {
			if (!vis[e.v]) {
				AllConditions(e.v, dest, wt + e.w, vis, psf + e.v + "");
			}
		}
		vis[src] = false;
	}

	// ****************************DFS(depth first search)
	public static void DFS(int src, boolean[] vis) {
		vis[src] = true;
		for (Edge e : graph.get(src)) {
			if (!vis[e.v]) {
				DFS(e.v, vis);
			}
		}
	}

	// *******************************************GET CONNECTED
	// *************COMPONENTS()************

	public static int gcc() {
		int comp = 0;
		boolean[] visited = new boolean[graph.size()];
		for (int i = 0; i < graph.size(); i++) {
			if (!visited[i]) {
				comp++;
				DFS(i, visited);
			}
		}
		return comp;
	}
	// *******************************************13 january
	// BFS, LEVEL,CYCLE,

	public static void BFS(int src) {// It is simple BFS
		LinkedList<Integer> queue = new LinkedList<>();
		boolean[] vis = new boolean[7];
		queue.add(src);

		while (queue.size() != 0) {
			int rem = queue.removeFirst();
			vis[rem] = true;
			System.out.println(rem);

			for (Edge e : graph.get(rem)) {
				if (!vis[e.v]) {
					queue.add(e.v);
				}
			}
		}
	}

	// ***********************************print level using BFS(level order of tree)
	public static void bfslevel(int src) {
		LinkedList<Integer> queue = new LinkedList<>();
		boolean[] vis = new boolean[7];
		queue.add(src);
		queue.add(-1);
		int level = 0;
		int dest = 6;
		int cycle = 0;

		while (queue.size() != 1) {

			Integer rem = queue.removeFirst();

			if (rem == -1) { // for increasing levels as encountered -1 t
								// then add -1 into last and level++;
				level++;
				queue.add(-1);
				continue;
			}
			if (vis[rem]) {
				cycle++; // for detecting cycles if encountered element true
							// increase cycle;
				System.out.println(cycle + "cycle");
				continue;
			}
			if (rem == dest) {
				System.out.println(level);
			}
			vis[rem] = true;
			// System.out.println(rem);

			for (Edge e : graph.get(rem)) {
				if (!vis[e.v]) {
					queue.add(e.v);
				}
			}

		}
	}

	public static void bfs2(int src) {
		LinkedList<Integer> queue = new LinkedList<>();
		boolean[] vis = new boolean[7];
		queue.add(src);
		// queue.add(-1);
		int level = 0;
		int dest = 6;
		int cycle = 0;

		while (queue.size() != 0) {
			int s = queue.size();
			while (s-- > 0) {
				int rem = queue.removeFirst();

				if (vis[rem]) {
					cycle++;
					System.out.println(cycle + "cycle");
					continue;
				}
				if (rem == dest) {
					System.out.println("levels" + level);
				}
				vis[rem] = true;

				for (Edge e : graph.get(rem)) {
					if (!vis[e.v]) {
						queue.add(e.v);
					}
				}
			}
			level++;
		}
	}

	// *******************************************18JANUARY*************************************

	// ***********************HAMILTONIAN PATH AND CYCLE BOTH
	public static void HamiltonianPath(int src, int osrc, boolean[] vis, int count, String path) {

		if (count == graph.size() - 1) {
			boolean flag = false;
			for (Edge e : graph.get(src)) { // for detecting cycle
				if (e.v == osrc) {
					System.out.println("Cycle: " + path);
					flag = true;
				}
			}

			if (!flag) { // if not cycle then there is a path
				System.out.println("Path: " + path);
			}
			return;
		}

		vis[src] = true;
		for (Edge e : graph.get(src)) {
			if (!vis[e.v]) {
				HamiltonianPath(e.v, osrc, vis, count + 1, path + e.v);
			}
		}
		vis[src] = false;

	}

	// ****************************************BIPARTITE GRAPH
	// we have to make a pair class
	static class bpair {
		int vert = 0;
		int clr = 0;

		bpair(int vert, int clr) {
			this.vert = vert;
			this.clr = clr;
		}
	}

	public static void bipartite() {
		int[] vis = new int[graph.size()];
		Arrays.fill(vis, -1);

		// for(int i=0;i<vis.length;i++) {
		// isBipartite(0,vis);
		// }
		System.out.println(isbipartite(0, vis));

	}

	public static boolean isBipartite(int i, int[] vis) {
		LinkedList<bpair> queue = new LinkedList<>();

		queue.add(new bpair(i, 0));
		while (queue.size() != 0) {

			bpair rem = queue.removeFirst();

			if (vis[rem.vert] != -1) {
				if (vis[rem.vert] != rem.clr) {
//					System.out.println("Conflict at:" + rem.vert);// not a bipartitie
					return false;
				} else {
//					System.out.println("no conflict at:" + rem.vert);// can bipartite
					continue;
				}
			}
			vis[rem.vert] = rem.clr;

			for (Edge e : graph.get(rem.vert)) {
				if (vis[e.v] == -1) {
					queue.add(new bpair(e.v, ((rem.clr + 1) % 2)));
				}
			}
		}
		return true;
	}

//	public static boolean isbipartite2(int src, int[] vis) {
//		LinkedList<bpair> queue = new LinkedList<>();
//		queue.add(new bpair(src, 0));
//		while (queue.size() != 0) {
//
//			bpair rem = queue.removeFirst();
//			if (vis[rem.vert] != -1) {
//				if (vis[rem.vert] != rem.clr) {
//					// System.out.println("Conflict at:"+rem.vert );
//					return false;
//				} else {
//					// System.out.println("no conflict at:"+rem.vert);
//					continue;
//				}
//			}
//			vis[rem.vert] = rem.clr;
//
//			for (Edge e : graph.get(rem.vert)) {
//				if (vis[e.v] == -1) {
//					queue.add(new bpair(e.v, ((rem.clr + 1) % 2)));
//				}
//			}
//		}
//		return true;
//	}

//**********************************************TOPOLOGICAL SORTING

	public static void Topological() {
		boolean[] vis = new boolean[8];
		boolean[] cycle = new boolean[8];
		LinkedList<Integer> st = new LinkedList<>();
		for (int i = 0; i < 8; i++) {
			if (!vis[i])
				if (cycleTopological(i, vis, cycle, st)) {
					System.out.println("Cycle Detected");
					return;
				}
		}

		while (!st.isEmpty()) {
			System.out.print(st.removeFirst() + " ");
		}
	}

	public static void TopoHelper() {
		boolean[] vis = new boolean[graph.size()];

		LinkedList<Integer> st = new LinkedList<>();
		for (int i = 0; i < graph.size(); i++) {
			if (!vis[i]) {
				TopologicalSort(i, vis, st);
			}
		}

		while (!st.isEmpty()) {
			System.out.print(st.removeFirst() + " ");
		}
	}

	public static void TopologicalSort(int src, boolean[] vis, LinkedList<Integer> st) {
		vis[src] = true;
		for (Edge e : graph.get(src)) {
			if (!vis[e.v]) {
				TopologicalSort(e.v, vis, st);
			}
		}

		st.addFirst(src);
	}

	// ****************************topological sort for cycle detection by 2boolean
	// visited arrays
	public static boolean cycleTopological(int src, boolean[] vis, boolean[] cycle, LinkedList<Integer> st) {
		boolean res = false;
		vis[src] = true;
		cycle[src] = true;
		for (Edge e : graph.get(src)) {
			if (!vis[e.v]) {
				res = res || cycleTopological(e.v, vis, cycle, st);
			} else if (cycle[e.v]) {
				return true;
			}

		}

		cycle[src] = false;
		st.addFirst(src);
		return res;
	}
	static boolean detect=false; 
	public static void cycle(int src, boolean[] vis, boolean[] cycle) {
		
		vis[src] = true;
		cycle[src] = true;
		for (Edge e : graph.get(src)) {
			if (!vis[e.v]) {
				cycle(e.v, vis, cycle);
			} else if (cycle[e.v]) {
				detect=true;
				return ;
			}

		}

		cycle[src] = false;
		
	}

	// **********************************KHANS
	// ALGO*********************************************************
	public static void KhansAlgo() {
		int[] indegree = new int[graph.size()];
		LinkedList<Integer> queue = new LinkedList<>();
		LinkedList<Integer> st = new LinkedList<>();

		for (int i = 0; i < graph.size(); i++) {
			for (Edge e : graph.get(i)) {
				indegree[e.v] += 1;
			}
		}

		for (int i = 0; i < indegree.length; i++) {
			if (indegree[i] == 0) {
				queue.add(i);
			}
		}

		while (queue.size() != 0) {

			int rem = queue.removeFirst();
//			st.add(rem);
			 System.out.println(rem);
			for (Edge e : graph.get(rem)) {
				indegree[e.v] -= 1;
				if (indegree[e.v] == 0) {
					queue.add(e.v);
				}
			}
		}
//**********for cycle detection check the size of the stack
		if (st.size() != graph.size()) { // if size is equal,cycle is not detected
			System.out.println("Cycle Detected:");
		} else {
			while (!st.isEmpty()) {
				System.out.print(st.removeFirst() + " ");
			}
		}
	}

//**************************************************************************************************************
	// *********************************Kosaraju Algorithm
	public static void Kosaraju() {
		boolean[] vis = new boolean[graph.size()];
		LinkedList<Integer> stack = new LinkedList<>();
		for (int i = 0; i < graph.size(); i++) {
			TopologicalSort(i, vis, stack);
		}
		constructGraph2();// reverse the graph
		// Constructor();
		display();

		boolean[] vis2 = new boolean[graph.size()];
		ArrayList<Integer> list = new ArrayList<>();
		while (!stack.isEmpty()) {
			int rem = stack.removeFirst();
			if (!vis2[rem]) {
				list.add(11);
				DFS2(rem, vis2, list);
			}
		}
		System.out.println(list);

	}

	public static void DFS2(int src, boolean[] vis, ArrayList<Integer> list) {
		vis[src] = true;
		list.add(src);
		for (Edge e : graph.get(src)) {
			if (!vis[e.v]) {
				DFS2(e.v, vis, list);
			}
		}
	}

	// *****************************************************************************************************
	// **********************************************Djikstra
	// (MINIMUM COST PATH)
	public static class pair implements Comparable<pair> {
		int wsf = 0;
		int vtx;

		pair(int vtx, int wsf) {
			this.vtx = vtx;
			this.wsf = wsf;
		}

		@Override
		public int compareTo(pair o) {

			return this.wsf - o.wsf;
		}
	}

	public static void Djikstra() {
		PriorityQueue<pair> pq = new PriorityQueue<>();
		pq.add(new pair(0, 0));
		int[] ans = new int[graph.size()];
		boolean[] vis = new boolean[graph.size()];
		while (pq.size() != 0) {
			pair rem = pq.remove();
			if (vis[rem.vtx]) {
				continue;
			}
			ans[rem.vtx] = rem.wsf;

			vis[rem.vtx] = true;
			for (Edge e : graph.get(rem.vtx)) {

				if (!vis[e.v]) {
					pq.add(new pair(e.v, rem.wsf + e.w));
				}
			}
		}

		for (int i = 0; i < ans.length; i++) {
			System.out.print(ans[i] + " ");
		}
	}

	// ************************************************Prims************************
//    System.out.println(rem.v+ "@"+ rem.cost +" via "+rem.path);
	public static class pair1 implements Comparable<pair1> {
		int cost = 0;
		int v;

		int pv;

		pair1(int pv, int v, int cost) {
			this.v = v;
			this.cost = cost;
//			this.path = path;
			this.pv = pv;
		}

		@Override
		public int compareTo(pair1 o) {

			return this.cost - o.cost;
		}
	}

	public static void Djikstra1() {
		PriorityQueue<pair1> pq = new PriorityQueue<>();
		pq.add(new pair1(-1, 0, 0));

		boolean[] vis = new boolean[graph.size()];

		while (pq.size() != 0) {

			pair1 rem = pq.remove();

			if (vis[rem.v]) {
				continue;
			}

			vis[rem.v] = true;
			if (rem.pv != -1)// add this edge pv-->vtx into new graph

				for (Edge e : graph.get(rem.v)) {
					if (!vis[e.v]) {
						pq.add(new pair1(rem.v, e.v, e.w));
					}
				}
		}
	}
	// **************************************union find

	// **************************************Articulation Point
	static int[] low = new int[graph.size()];
	static int[] dis = new int[graph.size()];
	static boolean[] vis = new boolean[graph.size()];
	static int time = 0;
	static int rt = 0;

	public static void ap() {
		for (int i = 0; i < dis.length; i++) {
			dis[i] = -1;
		}
		ap1(0, -1, 0);

		if (rt > 1) {
			System.out.println("0");
		}

		for (int i = 0; i < graph.size(); i++) {
			if (vis[i] && i != 0) {
				System.out.println(i);
			}
		}
	}

	private static void ap1(int src, int par, int osrc) {
		low[src] = dis[src] = time++;

		for (Edge e : graph.get(src)) {

			if (dis[e.v] == -1) {
				// unvisited)
				if (src == osrc) {
					rt++;
				}

				ap1(e.v, src, osrc);
				if (dis[src] <= low[e.v]) { // for articulation point
					vis[src] = true;
				}
				if (dis[src] < low[e.v]) {
					System.out.println("bridge from" + src + "to" + e.v);
				}

			} else if (e.v != par) {
				// visited
				low[src] = Math.min(low[src], dis[e.v]);
			}
		}

	}

	////////// Articulation point
	static int art = 0;
	static int bridge = 0;
	static int t = 0;
	static int[] lo = new int[graph.size()];
	static int[] di = new int[graph.size()];
	static int[] par = new int[graph.size()];
	static boolean[] visi = new boolean[graph.size()];
	static int p = 0;

	public static void Articulation() {

		arthelp(0, 0);
		if (p >= 2) {

		}
	}

	public static void arthelp(int src, int par) {
		t++;
		di[src] = lo[src] = t;
		visi[src] = true;
		for (Edge e : graph.get(src)) {

			if (e.v == par) {
				p++;
			}
			if (vis[e.v] == true && e.v != par) {
				low[src] = Math.min(di[e.v], lo[src]);
			} else if (!vis[e.v]) {
				arthelp(e.v, src);

				if (di[src] <= lo[e.v]) {
					art++;
				}
				if (di[src] < lo[e.v]) {
					bridge++;
				}
			}

		}

	}
}
