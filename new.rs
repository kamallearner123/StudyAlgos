#[derive(Debug)]
struct Person {
    name:String,
    id:u32
}

impl Person {
    pub fn new (name:String, id:u32) -> Person {
        Person{name, id}
    }

    pub fn greet(&self) -> String{
        format!("Hi... this is {}, and my id is {}", self.name, self.id)
    }
}

fn main() {
    let p1 = Person::new("Kamal".to_string(), 12);
    // println!(" P1 = {:?}", Person::new("kamal".to_string(),13));
    println!("{}",p1.greet());    
}
