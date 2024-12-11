fn main() {

    variables();
    data_types();
    functions();
    control_flow();
}  

fn variables(){
        //Variables-----------------------
        let x = 5;
        println!("x = {x}");
    
        //Will not compile since x is immutable by default 
            //x = 6;
            //println!("x = {x}");
    
        let mut q = 15;
        q += q - 2;
        println!("q = {q}");
    
        //Const, No let, No mut allowed, Data type required
        const SEVENTY_TWO_DAYS : u32 = 72;
        const SECONDS_IN_A_DAY: u32 = 60 * 60 * 24;
            //convention ^
    
        println!("72 days = {} seconds.", SEVENTY_TWO_DAYS * SECONDS_IN_A_DAY);
    
        //Shadowing (double let)
        let y = 2;
        let y = y + 4;
        println!("y = {}", y);
            //is valid, initial y is shadowed by predecessor 
    
        {
            let y = y*2;
            println!("y = {}", y);
    
            let y = "meow";
            println!("y = {}", y);
        }
    
        println!("y = {}", y);
        //y = 6,12,meow,6
}

fn data_types(){
    let str2num: u32 = "42".parse().expect("Not a number");
    print_type_of(&str2num); //prints u32

    //If an integer overflow occurs in release, Rust will wrap around
    //In debug mode it panics

    let _f: f32 = 0.5; //def is 64

    let _b: bool = true;
    let _heart_eyed_cat: char = '😻';

    //Tuples 
    let tup: (i32, bool, char) = (20, false, 'A');
    let (a,b,c) = tup;
    println!("{}, {}, {}", a,b,c);
    //OR
    println!("{}, {}, {}", tup.0,tup.1,tup.2);

    //Arrays
    let arr = [54,23,32,43,12];
    println!("{}", arr[0]);

    let arr2 = [0;5]; //0 repeated 5 times
    println!("{}", arr2[4]);
    


}

fn functions(){

    let x = {let y = 4; y + 1}; //Valid since {} evaluates to 5
    println!("x = {}", x); //prints x = 5

    let mut f = five();
    f += five();
    if f == 10{
        println!("10");
    }

}

fn control_flow(){
    let number = 5;

    if number > 0{ //needs to be a bool expression
        println!("do something if true");
    }
    else{
        println!("do something else if false");
    }

    if number % 2 == 0
        {println!("even");}
    else
        {println!("odd");}

    //if in let
    let _z: i32 =    if number > 0   { 10} 
                    else            {-10};

    //loops
    use ascii_converter::*;
    let mut index : u8 = 0;
    let initial: u8 = 65;
    loop{
        if index == 10 
            {break};

        let decimal_value: u8 = initial + index;
        let v = vec![decimal_value]; //usefuly for byte manipulations

        match decimals_to_string(&v){
            Ok(num) => println!("{} to ASCII: {}",decimal_value ,num),
            Err(e) => println!("* Error: {}", e),
        };
    index = index + 1;
    }

    //ALT
    println!("{} to ASCII: {}",75, 75 as char);


    //LOOP LABELS !? WTF this is cool
    let mut count = 0;
    'counting_up: loop {
        println!("count = {count}");
        let mut remaining = 10;

        loop {
            println!("remaining = {remaining}");
            if remaining == 9 {
                break;
            }
            if count == 2 {
                break 'counting_up;
            }
            remaining -= 1;
        }

        count += 1;
    }
    println!("End count = {count}");

    let mut b = 6;
    while b != 0{
        b -= 1;
    }


    let a = [10, 20, 30, 40, 50];

    for element in a {
        println!("the value is: {element}");
    }

    for number in (1..4).rev() {
        println!("{number}!");
    }
    println!("LIFTOFF!!!");

}

fn five() -> i32{ 
    5 //5; is a statement not an expression
    //return type needed for expressions
}

fn print_type_of<T>(_: &T) {
    println!("{}", std::any::type_name::<T>());
}