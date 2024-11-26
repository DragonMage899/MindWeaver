//Goal: Get user inpute, prcoess input and check input

use std::io;
use std::cmp::Ordering; //Enum
use rand::Rng;
//import io lib from std lib

fn main() {
    println!("Guess the Number!");

    let secret_number = rand::thread_rng().gen_range(1..=100);
    //println!("{}", secret_number);

    loop{
        println!("\nYour Guess?");

        let mut guess = String::new(); //returns an empty string
            //new is used like a default contructor 
        //Note: Variables are immutable be def

        io::stdin()
            .read_line(&mut guess)
                // store user input into guess variable 
                // mut -> can be changed within function
                // & -> reference, access data without copying 
            .expect("Failed to read line!");
                //catch

                //Note: Readline returns a Result Enum of state: Ok | Err
                //Err contains info about failure

        //convert guess from string to int
            //elim whitespace, newline, etc and parse->convert to sprecified type
        let guess: u32 = match guess.trim().parse(){
            Ok(num) => num,
            Err(_) => continue,
        }; //.expect("Please type a number!"); || added a match so this not needed

        //println!("You guessed: {}", guess);
            //Also valid: println!("You guessed: {guess}");
        //{} -> Placeholder
        //fills with commands seperated
        
        //match -> Made up of arms
        //-> Pattern to match against
        //Take a value and iterate through a list of patterns 

        match guess.cmp(&secret_number){ //returns a variant of Ordering 
            Ordering::Less => println!("Too Low!"),
            Ordering::Greater => println!("Too High!"),
            Ordering::Equal => {
                println!("Winner Winner Chicken Dinner!");
                break;

            }
        }
    }
}
