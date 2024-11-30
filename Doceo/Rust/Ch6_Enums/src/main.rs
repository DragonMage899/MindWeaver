fn main() {
    let ip_four = IpAddrKind::V4(127,0,0,1);
    let ip_six = IpAddrKind::V6(String::from("0000:0000:0000:0000:0000:0000:0000:0000"));

    route(ip_four);
    route(ip_six);

    let m = Message::_Write(String::from("Hello"));
    m.call();

    //Option enum

    let _some_number: Option<i32> = Some(5);
        //Only form of null in rust
    let _absent_number: Option<i32> = None;

    let five = Some(5);
    let six = plus_one(five);
    let none = plus_one(None);

    //Catch all
    let dice_roll = 10; //rand/inp
    
    match dice_roll {
        3 => add_fancy_hat(),
        7 => remove_fancy_hat(),
        _ => (),
    }

    match dice_roll {
        3 => add_fancy_hat(),
        7 => remove_fancy_hat(),
        _ => reroll(),
    }

    match dice_roll {
        3 => add_fancy_hat(),
        7 => remove_fancy_hat(),
        other => move_player(other),
    }


    //if let
    let config_max = Some(3u8);
    match config_max {
        Some(max) => println!("The maximum is configured to be {max}"),
        _ => (),
    }

    let config_max = Some(3u8);
    if let Some(max) = config_max {
        println!("The maximum is configured to be {max}");
    }



}

//Note: rust STL has an enum for IpAddr 
enum IpAddrKind{
    V4(u8, u8, u8, u8), 
    V6(String)
}

fn route(_ip: IpAddrKind){
    println!("Routing!");
}

enum Message{
    _Quit,
    _Move {x: i32, y: i32}, //names field data
    _Write(String), //plain data
    _ChangeColor(i32, i32, i32)
}

impl Message{
    fn call(&self){
        println!("calling");
    }
}

//Matching
enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(UsState),
}

fn _value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => 1,
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter(state) =>{println!("State -> {state:?}"); 25}
    }
}

#[derive(Debug)] // so we can inspect the state in a minute
enum UsState {
    Alabama,
    Alaska
}

fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1),
    }
}

fn add_fancy_hat() {}
fn remove_fancy_hat() {}
fn reroll() {}
fn move_player(x: i32) {}
