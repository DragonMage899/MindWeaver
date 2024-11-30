fn main() {

    basics();
    rectangles();
}

fn basics(){
    let mut user1 = Entity{
        username: String::from("Dragon"),
        hp: 100,
        mp: 10,
        lvl: 1
    };

    level_up(&mut user1);

    let mut mob1: Entity = make_monster(10, 5, 7);
    level_up(&mut mob1);

    //Copying
    let mut user2 = Entity{
        username: String::from("Gnome"),
        ..user1
    };

    level_up(&mut user2);
    level_up(&mut user1); 
        //If we took ownership of heap memory in user 2 with ..user 1, then this would not be valid

}

struct Entity{
    username: String,
    hp: i32,
    mp: i32,
    lvl: i32
}

    //shorhand
fn make_monster(hp: i32, mp: i32, lvl: i32) -> Entity{
    Entity{
        username: String::from("Monster"),
        hp, mp, lvl
    }
}

fn level_up(u : &mut Entity){
    u.lvl += 1;
    u.hp += 50;
    u.mp += 10;
    println!("{} has Levelled up!\nLevel: {}", u.username, u.lvl);
}  

//Tuple Struct
struct _Point(i32, i32, i32);

//Unit-like structs
struct _Worker;

fn rectangles(){
    let width = 30;
    let height = 50;

    println!("Area = {}", area(width, height));

    //refac 1
    let rec = (30,50);
    println!("Area = {}", area_tuple(rec));

    //refac 1
    let rect = Rectangle{ width: 30, height: 50};
    println!("Area = {}", area_struct(&rect));
    println!("rect = {:#?}", rect); //debug print || or :? 
        //needs #[derive(Debug)] before struct def

    dbg!(&rect); //pretty print with file and line info

    //Methods
    println!("Area = {}", rect.area());
    let rect2 = Rectangle{ width: 10, height: 10};
    let rect3 = Rectangle{ width: 100, height: 500};

    if rect.can_hold(&rect2){println!("Can fit!")}
    else{println!("Can't fit!")}

    if rect.can_hold(&rect3){println!("Can fit!")}
    else{println!("Can't fit!")}

    let sqr = Rectangle::square(10);
    dbg!(sqr);
}

fn area(width: u32, height: u32) -> u32{
    width * height
}

fn area_tuple(dim: (u32, u32)) -> u32{
    dim.0 * dim.1 // Can be confusing since tuple entries aren't names
}

#[derive(Debug)]
struct Rectangle{
    width: u32,
    height: u32
}

fn area_struct(rect: &Rectangle) -> u32{
    rect.height * rect.width
}

impl Rectangle{
    fn area(&self) -> u32{ //&mut self and self also allowed, self will take ownership
        self.width * self.height
    }

    fn can_hold(&self, rect2: &Rectangle) -> bool{
        //Expression lanfuages are cool :3
        self.height > rect2.height && self.width > rect2.width
    }

    //Helpers / constructors
    fn square(size: u32) -> Self{ //Can go in another impl block if needed
        Self{
            width: size,
            height: size
        }
    }
}
