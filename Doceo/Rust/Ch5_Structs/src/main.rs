fn main() {
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