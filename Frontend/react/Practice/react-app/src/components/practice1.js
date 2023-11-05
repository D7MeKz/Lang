import React from 'react'

const Practice1 = () => {
    const [inputs, setInputs] = useState({
        name:'',
        nickname : ''
      })
    const {name, nickname} = inputs;
    const nameInput = useRef();
    
    const onChange = e =>{
        const {value, name} = e.target;
        setInputs({
            ...inputs,
            [name]:value
        });
    }
    
    const onRest = ()=>{
        setInputs({
          name: '',
          nickname:''
        });
        nameInput.current.focus(); 
    }
    
    return (
    <div>
        <input
            name="name"
            placeholder="name"
            onChange={onChange}
            value={name}
            ref={nameInput}
        />
        <button onClick={onRest}>Init</button>
        <div>Value: {name} ({nickname})</div>
    </div>
    )
}

export default Practice1