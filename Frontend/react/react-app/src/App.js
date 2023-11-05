import React, {useState} from 'react';
import logo from './logo.svg';
import './App.css';


export default function App(){
  const [number, setNumber] = useState(1);
  return (
    <div id="container">
      <h1>Root</h1>
      <Right1 number = {number} onIncrease ={()=>{
        setNumber(number+1);
      }}></Right1>
      <Left1 number = {number}></Left1>
    </div>
  )
}

function Left1(props){
  return (
    <div>
      <p>Left1 : {props.number}</p>
      <Left2 number = {props.number}></Left2>
    </div>
  )
}

function Left2(props){
  return (
    <div>
      <p>Left2 : {props.number}</p>
      <Left3 number = {props.number}></Left3>
    </div>
  )
}

function Left3(props){
  return (
    <div>
      <p>Left3 : {props.number}</p>
    </div>
  )
}


// If you didn't use redux, you should get a value or function with props.. 
function Right1(props){
  return (
    <div>
      <p>Right1 : {props.number}</p>
      <Right2 number= {props.number} onIncrease={() => {props.onIncrease()}}></Right2>
    </div>
  )
}

function Right2(props){
  return (
    <div>
      <p>Right2 : {props.number}</p>
      <Right3 number={props.number} onIncrease={()=>{props.onIncrease()}}></Right3>
    </div>
  )
}

function Right3(props){
  return (
    <div>
      <p>Right3 : {props.number}</p>
      <input type='button' value="+" onClick={()=>{props.onIncrease()}}></input>
    </div>
  )
}