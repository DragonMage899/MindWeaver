pub fn add(left: u64, right: u64) -> u64 {
    left + right
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }
}

mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {println!("Adding to waitlist");}

        fn seat_at_table() {println!("Seating at table");}
    }

    mod serving {
        fn take_order() {println!("Taking order");}

        fn serve_order() {println!("Serving order");}

        fn take_payment() {println!("Taking payment");}
    }
}

mod back_of_house {
    fn fix_incorrect_order() {
        cook_order();
        super::deliver_order();
    }

    fn cook_order() {}

    pub struct Breakfast {
        pub toast: String,
        seasonal_fruit: String,
    }

    impl Breakfast {
        pub fn summer(toast: &str) -> Breakfast {
            Breakfast {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches"),
            }
        }
    }

    pub enum Appetizer {
        Soup,
        Salad,
    }
}

pub fn eat_at_restaurant() {
    // Absolute path, starts with crate
    //-> start from current dir: /../..
    //crate::front_of_house::hosting::add_to_waitlist();
        // Defined in same crate as eat_at_resturant()
        //

    // Relative path
        // Path starts with name of module:
        // -> /front_of_house/hosting/add_to_waitlist
    //front_of_house::hosting::add_to_waitlist();


    // Order a breakfast in the summer with Rye toast
    let mut meal = back_of_house::Breakfast::summer("Rye");
    // Change our mind about what bread we'd like
    meal.toast = String::from("Wheat");
    println!("I'd like {} toast please", meal.toast);

    // The next line won't compile if we uncomment it; we're not allowed
    // to see or modify the seasonal fruit that comes with the meal
    // meal.seasonal_fruit = String::from("blueberries");

    // Also, note that because back_of_house::Breakfast has a private field, 
    // the struct needs to provide a public associated function 
    // that constructs an instance of Breakfast (we’ve named it summer here). 
    // If Breakfast didn’t have such a function, we couldn’t create an instance of Breakfast
    
    let order1 = back_of_house::Appetizer::Soup;
    let order2 = back_of_house::Appetizer::Salad;

}

fn deliver_order() {}