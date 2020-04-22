class Solution {
    public List<List<String>> displayTable(List<List<String>> orders) {
        List<List<String>> res = new ArrayList();
		Set<String> foods = new TreeSet();
		HashMap<String, Integer> hm = new HashMap();
		for (List<String> order : orders) {
            foods.add(order.get(2));
		}

        int id = 0;
        List<String> head = new ArrayList();
		head.add("Table");
		for (String food : foods) {
			hm.put(food, id);
            head.add(food);
            id++;
		}
        res.add(head);
        
		int[][] a = new int[501][];
		for (List<String> order : orders) {
			int table = Integer.parseInt(order.get(1));
			if (a[table] == null) {
				a[table] = new int[hm.size()];
			}
			a[table][hm.get(order.get(2))]++;
		}
        
		for (int i = 0; i < 501; i++) {
			if (a[i] != null) {
				List<String> row = new ArrayList();
				row.add(String.valueOf(i));
				for (int j = 0; j < hm.size(); j++) {
					row.add(String.valueOf(a[i][j]));
				}
				res.add(row);
			}
		}
		return res;
    }
}