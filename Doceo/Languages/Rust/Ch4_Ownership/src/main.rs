fn main() {
    ownership();
    reference_and_borrow();
    slice();
}

fn ownership(){
    let _s1  = "meow"; //type string literal-> &str
        //Not useful for user input and other variable size operations
        //can't be mutated without first losing data
        //s1 += "2"; Not valid

    let mut s1 = String::from("Dragon"); //of type String
        //heap allocates string
        //can be mutated!

    s1.push_str(" Mage");

    println!("{}", s1);

    //Ownership:
    {
        let mut s2 = String::from("Dragon");
        s2.push_str(" Mage");
    }

    //println!("{}", s2); IS NOT VALID
    //s2 it out of scope
    //mem has been deallocated

        //move s1 into s2 
    let mut s2 = s1;
    //Pointer to the string is copied in this case
    s2.push_str(".");

    //println!("{}", s1); No longer valid since s2 owns the dynamic memory now
    println!("{}", s2);
    
    //CLone makes a deep copy
    let mut s3 = s2.clone();
    s3.push_str("\nHP: 727");
    println!("{}", s2);
    //s2 doesn't contain HP
    println!("{}", s3);
}

fn reference_and_borrow(){
    let s1 = String::from("Dragon Mage");

    let len = calculate_length(&s1);
    //s1 can still be used after this

    println!("The length of '{s1}' is {len}.\n----");
    

    let mut s2= String::from("Artorias");
    abyss(&mut s2);
    println!("{}", s2);

}

fn abyss(s: &mut String){
    s.push_str(" Abysswalker");
}

fn calculate_length(s: &String) -> usize {
    //Note: not allowed to mutate value within calc
    println!("----\nAddress: {:p}", s);
    println!("Value: {}", s);
    s.len()
}

fn slice(){
    let s = String::from("Curse you Bayle!!");
    let _i = first_word(&s);
    //if s goes out of scope or changes, i will lose meaning

    //Instead use slicing
    println!("{}", first_word_slice(&s));

    let a = [1, 2, 3, 4, 5];

    let slice = &a[1..3];
    assert_eq!(slice, &[2, 3]);

}

//& -> don't want ownership
fn first_word(s: &String) -> usize { //return index of first space (i.e end of first word)

    //conv String to arr of bytes
    let bytes = s.as_bytes(); //1 char = 1 byte

    for (i, &item) in bytes.iter().enumerate(){
        if item == b' '{return i;}
    }

    s.len()
}

fn first_word_slice(s: &str) -> &str { //can take in both String and str

    //conv String to arr of bytes
    let bytes = s.as_bytes(); //1 char = 1 byte

    for (i, &item) in bytes.iter().enumerate(){
        if item == b' '{return &s[0..i];}
    }

    &s[..]
}



