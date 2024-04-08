class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int l=0, cnt=0;
        for(int i=0; i<sandwiches.length; i++){
            int x= cnt, ok=0;
            do{
                if(students[l]==sandwiches[i]){
                    cnt++;
                    students[l]=-1;
                    break;
                }
                ok++;
                l= (l+1)%students.length;
            }while(ok<sandwiches.length);
            if(x==cnt) break;
        }
        return students.length-cnt;
    }
}