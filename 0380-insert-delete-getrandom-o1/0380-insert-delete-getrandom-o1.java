class RandomizedSet {

    HashMap<Integer, Integer> mp = new HashMap<>();
    ArrayList<Integer> nums = new ArrayList<>();
    public RandomizedSet() {
        mp = new HashMap<>();
        nums = new ArrayList<>();
    }
    
    public boolean insert(int val) {
        if(mp.containsKey(val)) return false;
        mp.put(val, nums.size());
        nums.add(val);
        return true;
    }
    
    public boolean remove(int val) {
        if(mp.containsKey(val)==false) return false;
        int idx = mp.get(val);
        if(idx < nums.size()-1){
            mp.put(nums.get(nums.size()-1), idx);
            nums.set(idx, nums.get(nums.size()-1));
        }
        mp.remove(val);
        nums.remove(nums.size()-1);
        return true;
    }
    
    public int getRandom() {
        Random rand = new Random();
        return nums.get(rand.nextInt(nums.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */