package selection_sort;

public class Selection {

	public static void main(String args[]) {
		
		int[] arr = {2,7,4,1,5,3};
		
		doSelectionSort(arr);
		
		for(int i=0; i<arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}
	
	public static void doSelectionSort(int[] a) {
		
		for(int i=0; i<a.length-1; i++) {
			int min_index = i;
			
			for(int j=i+1; j<a.length; j++) {
				if(a[j] < a[min_index]) {
					min_index = j;
				}
				
				int temp = a[i];
				a[i] = a[min_index];
				a[min_index] = temp;
			}
		}
	}
}
