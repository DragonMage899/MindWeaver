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
    mod hosting {
        fn add_to_waitlist() {println!("Adding to waitlist");}

        fn seat_at_table() {println!("Seating at table");}
    }

    mod serving {
        fn take_order() {println!("Taking order");}

        fn serve_order() {println!("Serving order");}

        fn take_payment() {println!("Taking payment");}
    }
}

pub fn eat_at_restaurant() {
    // Absolute path
    crate::front_of_house::hosting::add_to_waitlist();

    // Relative path
    front_of_house::hosting::add_to_waitlist();
}