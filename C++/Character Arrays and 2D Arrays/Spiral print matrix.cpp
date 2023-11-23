void spiralPrint(int **input, int nRows, int nCols)
{  
    int top = 0 , buttom = nRows-1 ;
    int left = 0 , right = nCols-1 ;

    while ( top <= buttom && left <=  right){
  
        for ( int i = left ; i <= right ; i++){
            cout << input [top][i] <<" ";
        }   top ++ ;


        for ( int i = top ; i<= buttom;i++){
            cout << input[i][right] <<" " ;
        }  right--;


        if ( top <= buttom) {

            for ( int i = right ; i >= left ; i--) {
                cout << input[buttom][i] <<" ";
            }   buttom-- ;
        }

        if ( left <=right) {

            for (int i = buttom; i >= top; i--) {
                cout << input[i][left] <<" ";
            }   left++;
        }
    }
}
