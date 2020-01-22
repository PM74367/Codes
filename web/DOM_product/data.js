var data=document.getElementById("enter"); 
var arr=[];
var qty=[];

function local()
{ 

var x=JSON.parse(localStorage.getItem("key"));//to print the local storage data
    if(x!=null)
    {
            for(var i=0;i<x.length;i++)
        {
            arr.push(x[i]);//pushing array in the json object etc....
            
            print(i);
        }
    }
}

local();

function delocal()
{
    localStorage.removeItem("key");
}

//local storage removal
document.getElementById("clear").addEventListener("click",function(event)
                                                { 
                                                    delocal();
                                                }
                                                );

document.getElementById("addInfo").addEventListener("click",
                                                    function(event)
                                                    {
                                                        detailsdom();
                                                    }
                                                    );

  //creating input panel                                              
  function detailsdom()
{   document.getElementById("addInfo").style.visibility="hidden";
    document.getElementById("list").style.visibility="hidden";

    var name=document.createElement("input");
    name.setAttribute("id","name");
    name.setAttribute("placeholder","Prodct_Name");
    name.setAttribute("style","width:250px");
    data.appendChild(name);
    
    newline(data);

    var rno=document.createElement("input");
    rno.setAttribute("id","rno");
    rno.setAttribute("placeholder","Product_ID");
    rno.setAttribute("style","width:250px");
    data.appendChild(rno);

    newline(data);


    var price=document.createElement("input");
    price.setAttribute("id","price");
    price.setAttribute("type","number");
    price.setAttribute("placeholder","Product_Price");
    price.setAttribute("style","width:250px");
    data.appendChild(price);

    newline(data);

    var btn=document.createElement("button");
    btn.setAttribute("id","btn");
    btn.innerHTML="Submit";
    btn.addEventListener("click",
                            function(event)
                            {   var x=0;
                                x=store();//x will be 1 if no data here
                                delpanel();
                                document.getElementById("addInfo").style.visibility="visible";
                                document.getElementById("list").style.visibility="visible";
                                if(x==0)
                                {
                                print(arr.length-1);
                                }
                            }
                        );
    data.appendChild(btn);
    newline(data);

    
}

//deleting the entry panel
function delpanel()
{
   
    var totalnodes=data.childNodes;
  
    for(var i =totalnodes.length-1; i>=0;i--)
    {
        data.removeChild(totalnodes[i]);
    } 

    
}

//to store data in array and also local storage
function store()
{
    var obj=new Object();
    var index=arr.length -1;
    obj.name=document.getElementById("name").value;
    obj.name=obj.name.toUpperCase();
    
    obj.rno=document.getElementById("rno").value;
    obj.rno=obj.rno.toUpperCase();

    obj.price=document.getElementById("price").value;
    if(obj.name=="" || obj.rno==""||obj.price=="")
    {return 1;} 
    else
    {
    arr.push(obj);
    localStorage.setItem("key",JSON.stringify(arr));
    return 0;
    }
}

//to add a new line
function newline(element)
{
    var br=document.createElement("br");
    element.appendChild(br);
}

//to print the list and creatinig elements in the list like delete and edit 
function print(i)
{      var abc=document.getElementById("list");
       var x=i
       var y=document.createElement("div");
       y.setAttribute("id",x);
                 
    
        var n=document.createElement("div");
        n.innerHTML=arr[x].name;
        n.style.color="Red";
        y.appendChild(n);
        
        var r=document.createElement("div");   
        r.innerHTML=arr[x].rno;
        r.style.color="Green";
        y.appendChild(r);

        var p=document.createElement("div");
        p.innerHTML=arr[x].price;
        p.style.color="Purple";
        y.appendChild(p);

        //creating delete element
        var link=document.createElement("a");
        link.setAttribute("href","#");
        link.innerHTML="Delete";
        link.addEventListener("click",function(event)
                         {
                             var targetparent=event.target.parentNode;
                             var index=parseInt(targetparent.id);
                             arr.splice(index,1); 
                             
                             targetparent.parentNode.removeChild(targetparent);

                             qty.splice(index,1);
                             var a1= document.getElementById("cart"+index);
                             a1.parentNode.removeChild(a1);
                             delocal();
                             localStorage.setItem("key",JSON.stringify(arr));

                             updatingindex(index);
                             
                         }                               
                         );

        y.appendChild(link);

        //edit part
        var xedit=document.createElement("a");
        xedit.setAttribute("href","#");
        xedit.innerHTML="Edit";
        xedit.addEventListener("click",function(event)
                                        {
                                           var tn=event.target.parentNode;
                                           var indx=parseInt(tn.id);
                                           newdetailsdom(indx);
                                        }
                                        );  
        newline(y);  
        y.appendChild(xedit);
        newline(y);
        //adding a button to add items to cart
        var add1=document.createElement("button");
        add1.innerHTML="Add to cart";
        add1.style.textAlign="left";
        add1.addEventListener("click",
                                function(event)
                                {
                                    var tn=event.target.parentNode;
                                    var indx=parseInt(tn.id);
                                    addtocart(indx);
                                }
                                );

        y.appendChild(add1);

        newline(y);
        newline(y);
        abc.appendChild(y);
        
        document.getElementById("addInfo").style.visibility="visible";
        document.getElementById("list").style.visibility="visible";
        
}

function updatingindex(index)
 { 

    var totalnodes=list.childNodes;
  
    for(var i =totalnodes.length-1; i>=index;i--)
    {
        list.removeChild(totalnodes[i]);
    } 
    

    var x=JSON.parse(localStorage.getItem("key"));//to print the local storage data
                             if(x!=null)
                             {
                                     for(var i=index;i<x.length;i++)
                                 {
                                     print(i);
                                 }
                             }
 }

//creating input panel with  array data itself                                        
function newdetailsdom(index)
{   document.getElementById("addInfo").style.visibility="hidden";
    document.getElementById("list").style.visibility="hidden";
    
    var name=document.createElement("input");
    name.setAttribute("id","name");
    
    name.setAttribute("style","width:250px");
    data.appendChild(name);
    name.value =arr[index].name;
    
    newline(data);

    var rno=document.createElement("input");
    rno.setAttribute("id","rno");
    rno.value=arr[index].rno;
    rno.setAttribute("style","width:250px");
    data.appendChild(rno);

    newline(data);

    var price=document.createElement("input");
    price.setAttribute("id","price");
    price.setAttribute("type","number");
    price.value=arr[index].price;
    price.setAttribute("style","width:250px");
    data.appendChild(price);

    newline(data);
   
    var btn=document.createElement("button");
    btn.setAttribute("id","btn");
    btn.innerHTML="Submit";
    btn.addEventListener("click",
                            function(event)
                            {
                                wstore(index);
                            }
                        );
    data.appendChild(btn);
    newline(data);

    
} 

//new store function to delete the array element and insert the new updated one
function wstore(indx)
{
   
   var obj=new Object();
   
   obj.name=document.getElementById("name").value;
   obj.name=obj.name.toUpperCase();
   
   obj.rno=document.getElementById("rno").value;
   obj.rno=obj.rno.toUpperCase();

   obj.price=document.getElementById("price").value;

   arr[indx]=obj;
   localStorage.setItem("key",JSON.stringify(arr));
   delpanel();
   var totalnodes=list.childNodes;
  
    for(var i =totalnodes.length-1; i>=indx;i--)
    {
        list.removeChild(totalnodes[i]);
    } 

    for(var i=indx;i<arr.length;i++)
        print(i);
  
}

//to add elements to the cart using another qty array
function addtocart(index)
{
    if(qty[index]==undefined)
    {
    var main=document.getElementById("cart");

    var big=document.createElement("div");
    big.setAttribute("class","row");
    big.setAttribute("id","cart"+index);

        var x=document.createElement("div");
        x.setAttribute("class","col-sm-8");
        x.innerHTML=arr[index].name ;
        big.appendChild(x);
        
        var y=document.createElement("input");
        y.setAttribute("id","qty"+index);
        y.setAttribute("class","col-sm-4");
        y.value=0+1;

        qty[index]=y.value;

        y.addEventListener("change",function(event)
        {
            qty[index]=y.value;
        }
        );
        big.appendChild(y);
    

     main.appendChild(big);
     newline(main);
    }
    else
    {
     qty[index]++;
     document.getElementById("qty"+index).value=qty[index];
    }
}

document.getElementById("bill").addEventListener("click",function(event)
{
    amount();
}
);
//to calculate price based on the number of items in cart and price of that 
function amount()
{
    /*
    below cart add 2 fiels one is button and other is input field with readonly attribute
    or try div also and change the innerhtml of div after calculating bill amount
    */
   var amt=0;
   for(var i=0;i<arr.length;i++)
   {
       console.log(qty[i]);
        if(qty[i]!=undefined)
        {amt=amt + parseInt(arr[i].price)*qty[i];}
   }

   document.getElementById("total").value=amt;
}
