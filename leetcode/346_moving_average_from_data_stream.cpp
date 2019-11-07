class MovingAverage {
    queue<int> int_container;
    int _size;
    int previous_sum;
    int window_counter;
    int one_previous;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        _size = size;
        previous_sum = 0;
        window_counter = 0;
        one_previous = 0;
    }
    
    double next(int val) {
        if(window_counter < _size){
            previous_sum += val;
            window_counter++;
            int_container.push(val);
        }
        else{
            // now full window
            previous_sum -= int_container.front();
            int_container.pop();
            previous_sum += val;
            int_container.push(val);
        }
        
        return (double)(previous_sum) / window_counter;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */