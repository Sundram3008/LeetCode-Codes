class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        int pc=0, mc=0, gc=0, pv=0, mv=0, gv=0;
        for(int i=0; i<garbage.length; i++){
            boolean pp=false, mp=false, gp=false;
            for(int j=0; j<garbage[i].length(); j++){
                if(garbage[i].charAt(j)=='P'){
                    pc++;
                    pp=true;
                }else if(garbage[i].charAt(j)=='G'){
                    gc++;
                    gp=true;
                }else{
                    mc++;
                    mp=true;
                }
            }
            if(pp){
                pc+= pv;
                pv=0;
            }
            if(mp){
                mc+= mv;
                mv=0;
            }
            if(gp){
                gc+= gv;
                gv=0;
            }
            if(i<travel.length){
                pv+= travel[i];
                mv+= travel[i];
                gv+= travel[i];
            }
        }
        return pc+gc+mc;
    }
}