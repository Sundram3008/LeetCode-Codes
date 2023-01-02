class Solution {
    public int evalRPN(String[] tokens) {
        Integer a, b;
        Stack<Integer> st = new Stack<>();
        for(int i=0; i<tokens.length; i++){
	            if(tokens[i].equals("+")){
	                a= st.peek();
	                st.pop();
	                b= st.peek();
	                st.pop();
	                st.push(b+a);
	            }
	            else if(tokens[i].equals("-")){
	                a= st.peek();
	                st.pop();
	                b= st.peek();
	                st.pop();
	                st.push(b-a);
	            }
	            else if(tokens[i].equals("*")){
	                a= st.peek();
	                st.pop();
	                b= st.peek();
	                st.pop();
	                st.push(b*a);
	            }
	            else if(tokens[i].equals("/")){
	                a= st.peek();
	                st.pop();
	                b= st.peek();
	                st.pop();
	                st.push(b/a);
	            }else {
	                a= Integer.parseInt(tokens[i]);
	                st.push(a);
	            }
	        }
	        return (int)st.peek();
    }
}