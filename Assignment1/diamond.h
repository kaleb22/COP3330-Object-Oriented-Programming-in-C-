// Name: Kaleb Dalla Pria       Section: 10    Recitation Class: Tu - 3:30pm - 4:50 pm

/*This is a class called Diamond and it objective is to create an object that represents a diamond. Also, 
 * with this class it is possible to manipulate the diamond and get some information about it just having 
 * the lenght of the side
 */
 
class Diamond {
    public:
    // functions must be public
    
    Diamond(int s, char b = '#', char in = '*');        // Constructor with 3 parameters. 2  are optional
    
    int GetSize();                                      // return size of the diamond                           
    int Perimeter();                                    // return perimeter of the diamond         
    double Area();                                      // return area of the diamond           
    
    
    void Grow();                                        // Increase the border in 1 unit           
    void Shrink();                                      // Decrease the border in 1 unit           
    
    
    void SetBorder(char b);                             // Change border character      
    void SetFill(char in);                              // Change inside character      
    
    void Draw();                                        // Show the diamond on the screen
    void Summary();                                     // Show a summary of the diamond information and draw it
    
    
    // Variables must be private
    private:
    int size;                                           // For storing the size of a Diamond
    char border;                                        // For sotring the border of a Diamond
    char inside;                                        // For storing the fill of a Diamond
};