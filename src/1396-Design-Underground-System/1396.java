class UndergroundSystem {

    HashMap<String, Pair<Integer, Integer>> check_out = new HashMap(); 
    HashMap<Integer, Pair<String, Integer>> check_in = new HashMap(); 
    
	public UndergroundSystem() {}
    
	public void checkIn(int id, String stationName, int t) {
        check_in.put(id, new Pair(stationName, t));
    }
    
	public void checkOut(int id, String stationName, int t) {
        Pair<String, Integer> checkIn = check_in.get(id);
        String name = checkIn.getKey() + ">" + stationName;
        int totalTime = t - checkIn.getValue();
        Pair<Integer, Integer> checkout = check_out.getOrDefault(name, new Pair(0, 0));
        check_out.put(name, new Pair<>(checkout.getKey() + totalTime, checkout.getValue() + 1));
    }
    
	public double getAverageTime(String startStation, String endStation) {
        String name = startStation + ">" + endStation;
        Pair<Integer, Integer> checkout = check_out.get(name);
        return (double) checkout.getKey() / checkout.getValue();
    }
}