#![crate_type = "lib"]
#[no_mangle]
pub extern "C" fn printInt(x: i32) {
    println!("{}", x);
}
