import React, {useState} from 'react';
import logo from './logo.svg';
import { Counter } from './features/counter/Counter';
import './App.css';
import { createStore } from '@reduxjs/toolkit';
import { Provider, useSelector, useDispatch, connect } from 'react-redux';

function reducer(currentState, action){
  if (currentState === undefined){
    return {
      number : 1,
    };
  }
  const newState = {...currentState}; // 객체 복제, Modify duplicated data 

  if(action.type === 'PLUS'){
    newState.number++;
  }
  return newState;
}
const store = createStore(reducer);

export default function App(){
  const [number, setNumber] = useState(1);
  return (
    <div id="container">
      <h1>Root</h1>
      <Provider store ={store}>
      <Right1 number = {number} onIncrease ={()=>{
        setNumber(number+1);
      }}></Right1>
      <Left1 number = {number}></Left1>
      </Provider>
    </div>
  )
}

function Left1(props){
  return (
    <div>
      <p>Left1</p>
      <Left2></Left2>
    </div>
  )
}

function Left2(props){
  return (
    <div>
      <p>Left2</p>
      <Left3></Left3>
    </div>
  )
}

function Left3(props){

  const number = useSelector((state)=> state.number ); // input is function  
  return (
    <div>
      <p>Left3 : {number}</p>
    </div>
  )
}


// If you didn't use redux, you should get a value or function with props.. 
function Right1(props){
  return (
    <div>
      <p>Right1</p>
      <Right2></Right2>
    </div>
  )
}

function Right2(props){
  return (
    <div>
      <p>Right2</p>
      <Right3></Right3>
    </div>
  )
}

function Right3(props){
  const dispatch = useDispatch()
  return (
    <div>
      <p>Right3</p>
      <input type='button' value="+" onClick={()=>{
        dispatch({type:'PLUS'}); // deliver the action, Call reducer
      }}></input>
    </div>
  )
}